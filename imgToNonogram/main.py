import sys
from pathlib import Path
import PIL.Image
import matplotlib.pyplot as plt
import numpy
import numpy as np


def tryParseInt(s, base=10, val=-1):
	try:
		return int(s, base)
	except ValueError:
		return val


def countTab(tab, size):
	index = 0
	retour = []
	for w in range(size):
		retour.append(0)

	for p in range(size):
		if tab[p] == 1:
			retour[index] = retour[index] + 1
		if p != 0:
			if tab[p - 1] == 1 and tab[p] == 0:
				index = index + 1

	return retour


taille = len(sys.argv)

if taille == 3:
	nom = sys.argv[1]
	tailleGrille = tryParseInt(sys.argv[2])

	while tailleGrille == -1:
		tailleGrille = tryParseInt(input("Taille du fichier : "))

	fileName = nom
	fileObj = Path(fileName)
	if not fileObj.is_file():
		print("Le fichier n'existe pas !")
	else:
		image_file = PIL.Image.open(nom)  # open colour image
		image_file = image_file.convert('1')  # convert image to black and white
		image_file = image_file.resize((tailleGrille, tailleGrille), PIL.Image.ANTIALIAS)
		image_file.save('result.png')
		print(image_file.size)  # Taille en pixels
		print(image_file.mode)  # Codage
		T = np.array(image_file)
		plt.imshow(T)  # Affichage étape 1
		plt.show()
		imageArray = []

		fichier = open("data.txt", "w")
		fichier.write(str(tailleGrille))
		fichier.write("\n")

		for i in range(tailleGrille):
			for j in range(tailleGrille):
				if T[i][j]:
					imageArray.append(0)
				else:
					imageArray.append(1)

		tableau = []

		for d in range(tailleGrille):
			tableau.append(0)

		for i in range(tailleGrille):
			for q in range(tailleGrille):
				tableau[q] = imageArray[i * tailleGrille + q]
				hintX = countTab(tableau, tailleGrille)

			for d in range(tailleGrille):
				if d == 0 or hintX[d] != 0:
					fichier.write(str(hintX[d]))
					if d < tailleGrille - 2:
						if hintX[d + 1] != 0:
							fichier.write(",")
				if d == tailleGrille - 1 and i != tailleGrille - 1:
					fichier.write(";")

		fichier.write("\n")

		for i in range(tailleGrille):
			for q in range(tailleGrille):
				tableau[q] = imageArray[i + tailleGrille * q]
				hintY = countTab(tableau, tailleGrille)

			for d in range(tailleGrille):
				if d == 0 or hintY[d] != 0:
					fichier.write(str(hintY[d]))
					if d < tailleGrille - 2:
						if hintY[d + 1] != 0:
							fichier.write(",")
				if d == tailleGrille - 1 and i != tailleGrille - 1:
					fichier.write(";")

		fichier.close()

else:
	print("Pour lancer le programe :\npython3 main.py <image> <taille>")
