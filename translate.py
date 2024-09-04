from deep_translator import GoogleTranslator
from pathlib import Path
import glob
import os

# get source and list files inside based arguments to filter the list
def getFiles(range_folder, root_path = ".", name_of_folder= "**", name_of_file = "**", extension_file="**" ):
    path_locate = Path(root_path)
    #List subdirectories
    path_located = [location for location in path_locate.iterdir() if location.is_dir()]
    search_pattern = os.path.join(root_path, name_of_folder, name_of_file, extension_file)   
    


    folder_list = []
    for i in range(range_folder):
        folder_names = list(path_located[i].glob(search_pattern))
        folder_list.extend(folder_names)
    
    return folder_list

def translateText(target, source="auto", text="Sample"):
    translate = GoogleTranslator( source=source, target=target).translate(text)
    return translate


def createOutFile(translated_text):
    #out_file = open('output.txt', 'w+b')
    #out_file.write(bytearray(translate, encoding='utf-8'))
    #out_file.close()
    return translated_text


print(getFiles(3))
