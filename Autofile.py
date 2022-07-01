#The code is used for making template for answers.
#Create folder
import os
for i in range(1,21):
    os.mkdir(f'Chapter {i}')
    #open file
    for j in range(1,13):
        with open(f'Chapter {i}/Q{j}.cpp','w') as f:
            pass