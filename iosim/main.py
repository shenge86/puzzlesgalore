# -*- coding: utf-8 -*-
"""
Created on Sun Mar  7 23:35:20 2021

@author: sheng
"""

import sys
import math
import random
import pygame as pg

BLACK = (0,0,0)
WHITE = (255,255,255)
LT_GRAY = (180,180,180)
GRAY = (120,120,120)
DK_GRAY = (80,80,80)

def main():
    """set up and run game screen and loop."""
    screen = pg.display.set_mode((639,360))
    pg.display.set_caption('Io Volcano')
    background = pg.image.load('tvashtar_plume.gif')
    
    # set up color-coded legend
    legend_font = pg.font.SysFont('None',24)

if __name__ == "__main__":
    pg.init()
    main()