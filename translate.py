from deep_translator import GoogleTranslator
from pathlib import Path
import glob

#get main folder
def getRootPath(root_path, range_folder):
    path_locate = Path(root_path)
    #List subdirectories
    path_located = [location for location in path_locate.iterdir() if location.is_dir()]

    folder_list = []
    for i in range(range_folder):
        folder_names = glob.glob(str(path_located[i]))
        folder_list.append(folder_names[0])

    #print(folder_list)
    return folder_list

# get source and list files inside based arguments to filter the list 
def listFilesOnTree(source_path=".", name_of_folder= "**", name_of_file = "**", extension_file="**"):
    for path in range(len(source_path)):
        source_path = Path(str(source_path[0]))
    
    list_of_folder = list(source_path.glob(f"{name_of_folder}/{name_of_file}/{extension_file}"))
    print(list_of_folder)
    return list_of_folder
       


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
source_path = getRootPath(root, 2)
listFilesOnTree(source_path)
translated_text = translateText(text, "portuguese")
createOutFile(translated_text)
