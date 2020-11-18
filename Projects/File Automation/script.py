import os, shutil, time
import PySimpleGUI as sg

def automate(path=None):
    files = os.listdir(path)
    if files != []:
        for f in files:
            splitted_file_name = f.split('.')
            extention = splitted_file_name[-1]
            try:
                if not os.path.exists(f"{path}/{extention}"):
                    os.mkdir(f"{path}/{extention}")
                if extention in f:
                    src = f"{path}/{f}"
                    dst = f"{path}/{extention}"
                    shutil.move(src,dst)
            except FileExistsError or FileNotFoundError:
                print("Error")
    else:
        return "empty"

def get_files(path=None):
    files = os.listdir(path)
    if files != []:
        return files
    else:
        return "empty"

layout = [
    [sg.Text("Enter Directory"), sg.Input(key='path')],
    [sg.Button("Manage"), sg.Button("Show"), sg.FileBrowse("Browse")],
    [sg.Text("Press Manage to move",key='ptext'),sg.ProgressBar(100,size=(28,20),key='pbar',bar_color=('lightgreen','snow'))],
    [sg.Listbox([],size=(58,10),key='file-list',no_scrollbar=False),],
]

window = sg.Window("File Manager", layout, finalize=True,)

listbox = window['file-list']
progressbar = window['pbar']
progressbar.hide_row()
listbox.hide_row()

while True:
    event, values = window.read()

    if event in ("Exit", None):
        break

    input_path = values['path']
    if input_path is not None and input_path != " " and input_path != "":
        try:
            total_files = 100 if len(get_files(input_path)) < 100 else len(get_files(input_path))
        except:
            sg.popup_error("Enter a valid directory",title="Error")

        if event == "Show":
            if get_files(input_path) == "empty":
                sg.popup("Enter a valid directory.")
            else:
                listbox.unhide_row()
                listbox.update(get_files(input_path))

        if event == "Manage":
            if get_files(input_path) != "empty":
                progressbar.update(total_files)
                progressbar.unhide_row()
                automate(input_path)
                for i in range(total_files+1):
                    window['pbar'].UpdateBar(i)
                    window['ptext'].update(f"Automated {i}")
                    time.sleep(0.009)
                sg.popup("Files moved successfully.", title="Message")
            else:
                sg.popup_error("Enter a valid directory",title='Error')
    else:
        sg.popup_error("Enter a valid directory",title='Err')

window.close()



