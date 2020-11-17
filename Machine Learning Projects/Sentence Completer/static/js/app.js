console.clear()
console.log("%cMade By Sethu Senthil", "font-weight: bold; font-size: 50px; color: blue; text-shadow: 1px 1px 0px black, 1px -1px 0px black, -1px 1px 0px black, -1px -1px 0px black;");
console.log('Website: ' + 'https://sethusenthil.com')
console.log('TikTok: ' + 'https://tiktok.com/@sethusenthil')
console.log('Insta: ' + 'https://instagram.com/sethui9')

let mode = 'word'
var textOutput = document.querySelector('#output');
var recognition = new webkitSpeechRecognition() ||
    root.mozSpeechRecognition ||
    root.msSpeechRecognition ||
    root.oSpeechRecognition ||
    root.SpeechRecognition;
recognition.continuous = true;


function stopListening() {
    recognition.stop()
}
function startListening() {
    //reset state
    document.querySelector('#output').innerText = ''
    document.querySelector('#main-btn').disabled = true

    recognition.onstart = function() {
        //onstart
    }
    recognition.onresult = function(event) {
        document.querySelector('.progress').display = 'block'
        stopListening()
        console.log(event);
        textOutput.innerHTML = "";

        for (var i = 0; i < event.results.length; i++) {
            textOutput.innerHTML = textOutput.innerHTML + event.results[i][0].transcript;
        }


        if(mode == 'lasWord'){
        $.ajax({
            url: '/get_end_predictions',
            type: "post",
            contentType: "application/json",
            dataType: "json",
            data: JSON.stringify({
                "input_text": textOutput.innerText + ' ',
                "top_k": 5,
            }),
        }).done(function (jsondata, textStatus, jqXHR) {
            console.log(jsondata)

            let data = jsondata.roberta.split("\n")
            let cleanArr = []
            data.forEach(word => {
                //check if verb
                if(!word.includes(word.toLowerCase())){
                    cleanArr.push(word)
                }
            });
            if(cleanArr.length === 0){
                cleanArr = data
            }

            document.querySelector('.progress').display = 'none'
            textOutput.innerHTML += `<b>${cleanArr[0]}</b>`;


            let msg = new SpeechSynthesisUtterance();
    msg.text = cleanArr[0];
    window.speechSynthesis.speak(msg);
    document.querySelector('#main-btn').disabled = false
        })
    }else if(mode == 'word'){

        $.ajax({
            url: '/get_mask_predictions',
            type: "post",
            contentType: "application/json",
            dataType: "json",
            data: JSON.stringify({
                "input_text": textOutput.innerText.replace('blank', '<mask>'),
                "top_k": 5,
            }),
            beforeSend: function () {

            },
            complete: function () {

            }
        }).done(function (jsondata, textStatus, jqXHR) {
            console.log(jsondata)
            let data = jsondata.roberta.split("\n")
            document.querySelector('.progress').display = 'none'

            document.querySelector('#output').innerHTML =  document.querySelector('#output').innerHTML.replace('blank', `<b>${data[0]}</b>`)
            let msg = new SpeechSynthesisUtterance();
     msg.text = textOutput.innerHTML;
     window.speechSynthesis.speak(msg);
     document.querySelector('#main-btn').disabled = false

        }).fail(function (jsondata, textStatus, jqXHR) {
            console.log(jsondata)
        });
    }
    }
    recognition.start();

    recognition.onend = function() {
       //on end
       document.querySelector('#main-btn').disabled = false
    }
}
