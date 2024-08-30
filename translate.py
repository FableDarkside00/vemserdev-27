from deep_translator import GoogleTranslator
from pathlib import Path
import glob

# get source and list files inside based arguments to filter the list
def getFiles(range_folder, root_path = ".", name_of_folder= "**", name_of_file = "**", extension_file="**" ):
    path_locate = Path(root_path)
    #List subdirectories
    path_located = [location for location in path_locate.iterdir() if location.is_dir()]

    folder_list = []
    for i in range(range_folder):
        folder_names = glob.glob(str(path_located[i]))
        folder_list.extend(folder_names)

    #List files
    files = []
    for paths in folder_list:
        files.extend(glob.glob(f"{paths}/{name_of_folder}/{name_of_file}/{extension_file}"))
   
    return files


def translateText(text, target, source="auto"):
    translate = GoogleTranslator( source=source, target=target).translate(text)
    return translate


def createOutFile(translated_text):
    #out_file = open('output.txt', 'w+b')
    #out_file.write(bytearray(translate, encoding='utf-8'))
    #out_file.close()
    return translated_text


text = "Sample of text"
root = './BipEmulator-master/src/'
print(getFiles(2, root))
translated_text = translateText(text, "portuguese")
createOutFile(translated_text)