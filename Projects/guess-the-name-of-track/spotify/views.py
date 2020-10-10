from django.shortcuts import render
from django.shortcuts import redirect
import requests
import datetime
import base64
import string
import random
from urllib.parse import urlencode
import json
from .forms import ArtistForm
score = 0
choice = 0
endpoint = None
track_number = 0
chosen_track = None
playlist_track = None
game_over=None

class SpotifyAPI(object):
    access_token = None
    access_token_expires = datetime.datetime.now()
    access_token_did_expire = True
    client_id = None
    client_secret = None
    token_url = "https://accounts.spotify.com/api/token"

    def __init__(self, client_id, client_secret, *args, **kwargs):
        super().__init__(*args, **kwargs)
        self.client_id = client_id
        self.client_secret = client_secret

    def get_client_credentials(self):
        """
        Returns a base64 encoded string
        """
        client_id = self.client_id
        client_secret = self.client_secret
        if client_secret == None or client_id == None:
            raise Exception("You must set client_id and client_secret")
        client_creds = f"{client_id}:{client_secret}"
        client_creds_b64 = base64.b64encode(client_creds.encode())
        return client_creds_b64.decode()

    def get_token_headers(self):

        client_creds_b64 = self.get_client_credentials()
        return {
            "Authorization": f"Basic {client_creds_b64}"
        }

    def get_token_data(self):

        return {
            "grant_type": "client_credentials"
        }

    def perform_auth(self):
        token_url = self.token_url
        token_data = self.get_token_data()
        token_headers = self.get_token_headers()
        r = requests.post(token_url, data=token_data, headers=token_headers)
        if r.status_code not in range(200, 299):
            return False
        data = r.json()
        now = datetime.datetime.now()
        access_token = data['access_token']
        expires_in = data['expires_in']  # seconds
        expires = now + datetime.timedelta(seconds=expires_in)
        self.access_token = access_token
        self.access_token_expires = expires
        self.access_token_did_expire = expires < now
        return True


client_id = 'client_id'
client_secret = 'client_secret'
spotify = SpotifyAPI(client_id, client_secret)



def index(request):
    global choice, endpoint, spotify, track_number, chosen_track, playlist_track,game_over,score
    choices_urls = {
        "pop": "https://api.spotify.com/v1/playlists/37i9dQZF1DXcBWIGoYBM5M/tracks",
        "hip-hop": "https://api.spotify.com/v1/playlists/37i9dQZF1DX5qgrUJCOKNp/tracks",
        "kpop": "https://api.spotify.com/v1/playlists/37i9dQZF1DX9tPFwDMOaN1/tracks",
        "rock": "https://api.spotify.com/v1/playlists/37i9dQZF1DWXRqgorJj26U/tracks",
        "R&B": "https://api.spotify.com/v1/playlists/37i9dQZF1DWYmmr74INQlb/tracks",
        "jazz": "https://api.spotify.com/v1/playlists/37i9dQZF1DXbITWG1ZJKYt/tracks",
        "Blues": "https://api.spotify.com/v1/playlists/37i9dQZF1DXd9rSDyQguIk/tracks",
        "punk": "https://api.spotify.com/v1/playlists/37i9dQZF1DX3LDIBRoaCDQ/tracks",
        "country": "https://api.spotify.com/v1/playlists/37i9dQZF1DWVpjAJGB70vU/tracks",
        "electronic/dance": "https://api.spotify.com/v1/playlists/37i9dQZF1DXa8NOEUWPn9W/tracks",
        "khaleji": "https://api.spotify.com/v1/playlists/37i9dQZF1DWU486KSiznWZ/tracks",
        "reggae": "https://api.spotify.com/v1/playlists/37i9dQZF1DXbSbnqxMTGx9/tracks",
        "rap_fr": "https://api.spotify.com/v1/playlists/167iCb4j4Yc35hM21RB495/tracks",
        "tiktok_songs":"https://api.spotify.com/v1/playlists/37i9dQZF1DX2L0iB23Enbq/tracks"

    }


# use of the object
    spotify.perform_auth()
    access_token = spotify.access_token
    headers = {
        "Authorization": f"Bearer {access_token}"
    }

    submit_value = request.POST.get("submit", None)
    if submit_value is not None:
        endpoint = choices_urls[request.POST["choices"]]
        data = urlencode({"market": "MA",
                          'offset': 0})
        lookup_url = f"{endpoint}?{data}"
        r = requests.get(lookup_url, headers=headers)
        playlist_track = r.json()['items']
        random.shuffle(playlist_track)
# get random numbers for choosing the music choices
    sampling_list = list(range(len(playlist_track)))
    del sampling_list[track_number]
    random_numbers = random.sample(sampling_list, 3)


    preview_url = playlist_track[track_number]['track']['preview_url']

    chosen_track = playlist_track[track_number]['track']['name']
    choices = [
        playlist_track[track_number]['track']['name']
    ]
    choices += [playlist_track[x]['track']['name'] for x in random_numbers]
    random.shuffle(choices)
    

    data_view = {"preview_url": preview_url, "choices": choices }
    if data_view["preview_url"] == None:
        track_number += 1
        if track_number < len(playlist_track):
            return redirect('/spotify')
        else:
            game_over = {"score": score}
            score=0
            track_number=0
            return redirect('/spotify/page',game_over)
    else:
        return render(request, 'spotify/index.html', data_view)


def choices(request):
    score=0
    return render(request, 'spotify/choices.html')


def gameOver(request):
    return render(request, 'spotify/gameover.html')


def data(request):
    global score, chosen_track, track_number, playlist_track,game_over
    return_val = None
    if request.POST["submit"] == "submit-one":
        if request.POST["anwser"] == chosen_track:
            score += 1
            track_number += 1
            if track_number < len(playlist_track):
                return_val = redirect('/spotify')
            else:
                game_over = {"score": score}
                track_number=0
                return_val = redirect('/spotify/page',game_over)
                score=0
        else:
            game_over = {"score": score}
            track_number=0
            return_val = render(request, 'spotify/gameover.html', game_over)
            score=0
    chosen_track = None
    return return_val
def page(request):
    return render(request,'spotify/page.html',game_over)
