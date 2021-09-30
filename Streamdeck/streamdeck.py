import subprocess
import serial
import webbrowser
#import wx ou un truc dans le genre

#csgo = 'C:\Program Files (x86)\Steam\steamapps\common\Counter-Strike Global Offensive\csgo.exe'
#csgo = 'C:\Program Files (x86)\Steam//rungameid/222980'
steam = 'C:\Program Files (x86)\Steam\steam.exe'
csgo = 'C:\Program Files (x86)\Steam//rungameid/624820'
vibrance = 'C:\Program Files\VibranceGUI//vibranceGUI.exe'
chrome = 'C:\Program Files (x86)\Google\Chrome\Application\chrome.exe'

ENT = 'https://ent.univ-tlse3.fr/uPortal/f/student/normal/render.uP'

boutontmp=""
bouton=""

# donne la chaine de caractère contenant le bouton b1, b2, ... à partir de l'entrée par le port série
def donneBouton(chaine):
    tmp=list(chaine[:-2])
    bouton=[]
    for elem in tmp:
        bouton.append(chr(elem))
    bouton="".join(bouton)
    return bouton


com5 = serial.Serial(port = "COM5", baudrate=9600)
com5.ReadTimeout=5

# def de chrome en navigateur par défaut
webbrowser.register('gchrome', None,webbrowser.BackgroundBrowser(chrome))

# On lit ce qui arrive que le port série don ce qui est envoyé par l'arduino
boutontmp=com5.readline()
bouton=donneBouton(boutontmp)

while(bouton!="stop"):
    if(bouton=="b1"):
        test=subprocess.Popen(steam)
        test.wx_attributes("-topmost",1)
    elif(bouton=="b2"):
        subprocess.Popen(vibrance)
    elif(bouton=="b3"):
        webbrowser.get('gchrome').open_new_tab(ENT)
    
    boutontmp=com5.readline()
    bouton=donneBouton(boutontmp)

com5.close()

