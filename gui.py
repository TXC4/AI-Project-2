import pygame
import csv

pygame.init()

white = (255,255,255)
black = (0,0,0)

red = (255,0,0)
green = (0,255,0)
blue = (0,0,255)
yellow = (255,255,0)
purple = (255,0,255)

gameDisplay = pygame.display.set_mode((1920,1080))
gameDisplay.fill(black)
pixAr = pygame.PixelArray(gameDisplay)
pixAr[10][20] = green 

oradeaColor = red
zerindColor = red
aradColor = red
timisoaraColor = red
lugojColor = red
mehadiaColor = red
drobetaColor = red
craiovaColor = red
rvColor = red
sibiuColor = red
fagarusColor = red
pitestiColor = red
bucharestColor = yellow
giurgiuColor = red
urziceniColor = red
hirsovaColor = red
eforieColor = red
vasluiColor = red
iasiColor = red
neamtColor = red

def resetBoard():
    global oradeaColor, zerindColor, aradColor, timisoaraColor, lugojColor, mehadiaColor, drobetaColor, craiovaColor, rvColor, sibiuColor, fagarusColor, pitestiColor, bucharestColor, giurgiuColor, urziceniColor, eforieColor, vasluiColor, iasiColor, neamtColor
    oradeaColor = red
    zerindColor = red
    aradColor = red
    timisoaraColor = red
    lugojColor = red
    mehadiaColor = red
    drobetaColor = red
    craiovaColor = red
    rvColor = red
    sibiuColor = red
    fagarusColor = red
    pitestiColor = red
    bucharestColor = yellow
    giurgiuColor = red
    urziceniColor = red
    hirsovaColor = red
    eforieColor = red
    vasluiColor = red
    iasiColor = red
    neamtColor = red

priorVisitedList = None
priorPathList = None

while True:
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            pygame.quit()
            quit()
    clock = pygame.time.Clock()
    clock.tick(5)

    gameDisplay.fill(black)

    with open('C:/Users/Carlton/source/repos/AI Project 2/AI Project 2/visited.txt') as csv_file:
        reader = csv.reader(csv_file, delimiter=',')
        data = list(reader)

    #check if change made to visited.txt
    if priorVisitedList != None and priorVisitedList != data:
        resetBoard()
        
    if "Oradea" in data[0]:
        oradeaColor = blue
    if "Zerind" in data[0]:
        zerindColor = blue
    if "Arad" in data[0]:
        aradColor = blue
    if "Timisoara" in data[0]:
        timisoaraColor = blue
    if "Lugoj" in data[0]:
        lugojColor = blue
    if "Mehadia" in data[0]:
        mehadiaColor = blue
    if "Drobeta" in data[0]:
        drobetaColor = blue
    if "Craiova" in data[0]:
        craiovaColor = blue
    if "Rimnicu Vilcea" in data[0]:
        rvColor = blue
    if "Sibiu" in data[0]:
        sibiuColor = blue 
    if "Fagarus" in data[0]:
        fagarusColor = blue
    if "Pitesti" in data[0]:
        pitestiColor = blue
    if "Bucharest" in data[0]:
        bucharestColor = blue
    if "Giurgiu" in data[0]:
        giurgiuColor = blue
    if "Urziceni" in data[0]:
        urziceniColor = blue
    if "Hirsova" in data[0]:
        hirsovaColor = blue
    if "Eforie" in data[0]:
        eforieColor = blue
    if "Vaslui" in data[0]:
        vasluiColor = blue
    if "Iasi" in data[0]:
        iasiColor = blue
    if "Neamt" in data[0]:
        neamtColor = blue

    priorVisitedList = data
    csv_file.close()

    with open('C:/Users/Carlton/source/repos/AI Project 2/AI Project 2/path.txt') as csv_file:
        reader = csv.reader(csv_file, delimiter=',')
        data2 = list(reader)

    #check if change made to path.txt
    if priorPathList != None and priorPathList != data2:
        resetBoard()

    if "Oradea" in data2[0]:
        oradeaColor = green
    if "Zerind" in data2[0]:
        zerindColor = green
    if "Arad" in data2[0]:
        aradColor = green
    if "Timisoara" in data2[0]:
        timisoaraColor = green
    if "Lugoj" in data2[0]:
        lugojColor = green
    if "Mehadia" in data2[0]:
        mehadiaColor = green
    if "Drobeta" in data2[0]:
        drobetaColor = green
    if "Craiova" in data2[0]:
        craiovaColor = green
    if "Rimnicu Vilcea" in data2[0]:
        rvColor = green
    if "Sibiu" in data2[0]:
        sibiuColor = green 
    if "Fagarus" in data2[0]:
        fagarusColor = green
    if "Pitesti" in data2[0]:
        pitestiColor = green
    if "Bucharest" in data2[0]:
        bucharestColor = green
    if "Giurgiu" in data2[0]:
        giurgiuColor = green
    if "Urziceni" in data2[0]:
        urziceniColor = green
    if "Hirsova" in data2[0]:
        hirsovaColor = green
    if "Eforie" in data2[0]:
        eforieColor = green
    if "Vaslui" in data2[0]:
        vasluiColor = green
    if "Iasi" in data2[0]:
        iasiColor = green
    if "Neamt" in data2[0]:
        neamtColor = green

    priorPathList = data2
    csv_file.close()

    pygame.draw.line(gameDisplay, red, (200,50), (170,150),5)
    pygame.draw.line(gameDisplay, red, (200,50), (450,270), 5)
    pygame.draw.line(gameDisplay, red, (170,150), (160,240),5)
    pygame.draw.line(gameDisplay, red, (160,240), (170,500),5)
    pygame.draw.line(gameDisplay, red, (160,240), (450,270),5)
    pygame.draw.line(gameDisplay, red, (170,500), (300,600),5)
    pygame.draw.line(gameDisplay, red, (300,600), (310,700),5)
    pygame.draw.line(gameDisplay, red, (310,700), (300,800),5)
    pygame.draw.line(gameDisplay, red, (300,800), (530,850),5)
    pygame.draw.line(gameDisplay, red, (530,850), (500,500),5)
    pygame.draw.line(gameDisplay, red, (530,850), (715,620),5)
    pygame.draw.line(gameDisplay, red, (500,500), (450,270),5)
    pygame.draw.line(gameDisplay, red, (715,620), (500,500),5)
    pygame.draw.line(gameDisplay, red, (450,270), (700,240),5)
    pygame.draw.line(gameDisplay, red, (700,240), (950, 700),5)
    pygame.draw.line(gameDisplay, red, (950,700), (715,620),5)
    pygame.draw.line(gameDisplay, red, (950,700), (900, 900),5)
    pygame.draw.line(gameDisplay, red, (950,700), (1050, 700),5)
    pygame.draw.line(gameDisplay, red, (200,50), (170,150),5)
    pygame.draw.line(gameDisplay, red, (1050, 700), (1200,350),5)
    pygame.draw.line(gameDisplay, red, (1050, 700), (1300, 700),5)
    pygame.draw.line(gameDisplay, red, (1200,350), (1100, 220),5)
    pygame.draw.line(gameDisplay, red, (1300, 700), (1400, 850),5)
    pygame.draw.line(gameDisplay, red, (1100, 220), (915,100),5)

    pygame.draw.circle(gameDisplay, oradeaColor, (200,50), 20)#oradea
    pygame.draw.circle(gameDisplay, zerindColor, (170,150), 20)#zerind
    pygame.draw.circle(gameDisplay, aradColor, (160,240), 20)#arad
    pygame.draw.circle(gameDisplay, timisoaraColor, (170,500), 20)#timisoara
    pygame.draw.circle(gameDisplay, lugojColor, (300,600), 20)#lugoj
    pygame.draw.circle(gameDisplay, mehadiaColor, (310,700), 20)#mehadia
    pygame.draw.circle(gameDisplay, drobetaColor, (300,800), 20)#drobeta
    pygame.draw.circle(gameDisplay, craiovaColor, (530,850), 20)#craiova
    pygame.draw.circle(gameDisplay, rvColor, (500,500), 20)#rimnieu vilcea
    pygame.draw.circle(gameDisplay, sibiuColor, (450,270), 20)#sibiu
    pygame.draw.circle(gameDisplay, fagarusColor, (700,240), 20)#fagarus
    pygame.draw.circle(gameDisplay, pitestiColor, (715,620), 20)#pitesti
    pygame.draw.circle(gameDisplay, bucharestColor, (950, 700), 20)#bucharest
    pygame.draw.circle(gameDisplay, giurgiuColor, (900, 900), 20)#giurgiu
    pygame.draw.circle(gameDisplay, urziceniColor, (1050, 700), 20)#urziceni
    pygame.draw.circle(gameDisplay, hirsovaColor, (1300, 700), 20)#hirsova
    pygame.draw.circle(gameDisplay, eforieColor, (1400, 850), 20)#eforie
    pygame.draw.circle(gameDisplay, vasluiColor, (1200,350), 20)#vaslui
    pygame.draw.circle(gameDisplay, iasiColor, (1100, 220), 20)#iasi
    pygame.draw.circle(gameDisplay, neamtColor, (915,100), 20)#neamt
    
    pygame.display.update()
