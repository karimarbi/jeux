#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h> 

int main(int argc, char *argv[])
{
    SDL_Surface  *ecran = NULL, *imageDeFond = NULL, *image1 = NULL,*image2 = NULL, *image3=NULL, *image4=NULL, *image5=NULL,*image6=NULL, *image1a = NULL,*image2a = NULL, *image3a=NULL,*image8=NULL,*image9=NULL, *image10 = NULL,*image11 = NULL, *image12=NULL,*image13=NULL,*image14=NULL,*image15=NULL,*image16=NULL,*image10a = NULL,*image11a = NULL,*title=NULL, *image12a=NULL,*image13a=NULL,*image14a=NULL,*image15a=NULL,*image16a=NULL,*text=NULL, *imageDeFond1 = NULL ; 
    SDL_Rect positiontext,positionFond,positionimage1, positionimage2,positionimage3,positionclic,positionimage4,positionimage5,positionimage6,positionimage8,positionimage9,positionimage1a, positionimage2a,positionimage3a, positionimage4a,positionimage11, positionimage12,positionimage13, positionimage14,positionimage15,positionimage16,positionimage10,positionimage11a, positionimage12a,positionimage13a, positionimage14a,positionimage15a,positionimage16a,positionimage10a,positiontitle,positionFond1;
    putenv("SDL_VIDEO_CENTERED=1"); //centrer l ecran
//set pos x et y
    positiontext.x=600;
    positiontext.y=400;
    positionFond.x = 0;
    positionFond.y = 0;
    positionFond1.x = 100;
    positionFond1.y = 0;
    positionimage1.x = 200-50; // pos play
    positionimage1.y = 200+150;
    
    positionimage2.x = 200-50; // option
    positionimage2.y = 320+150;
    
    positionimage3.x = 200-50;//exit
    positionimage3.y = 440+150; 

    positiontitle.x =500; // pos titre
    positiontitle.y =70;
    
    positionimage4.x = 0;
    positionimage4.y = 0;
    positionimage5.x = 0;
    positionimage5.y = 0;
    positionimage6.x = 0;
    positionimage6.y = 0;
    
    positionimage1a.x = 200-50; // play clicked
    positionimage1a.y = 200+150;
    
    positionimage2a.x = 200-50; // option clicked
    positionimage2a.y = 320+150;
    
    positionimage3a.x = 200-50; // exit clicked
    positionimage3a.y = 440+150;
    
    positionimage8.x = 300; // click to start
    positionimage8.y = 620+100;
    
    positionimage10.x = 50 ; //return to main menu
    positionimage10.y = 50;
    
    positionimage11.x = 300 ; // click to "text"
    positionimage11.y = 620+100;
    
    positionimage12.x = 670;//fullscreen
    positionimage12.y = 625;
    
    positionimage13.x = 670+230;//fullscreen
    positionimage13.y = 625;
    
    positionimage14.x = 630+230;//off button
    positionimage14.y = 410;
    
    positionimage15.x = 580+50;//volume slider
    positionimage15.y = 520;
    
    positionimage16.x = 560+100;//on button
    positionimage16.y = 410;
    
    positionimage10a.x = 50 ;//return to main menu clicked
    positionimage10a.y = 50;
    
    positionimage11a.x = 300;
    positionimage11a.y = 620+100;
    
    positionimage12a.x = 670;//fullscreen
    positionimage12a.y = 625;
    
    positionimage13a.x = 670+230;//fullscreen
    positionimage13a.y = 625;
    
    positionimage14a.x = 630+230;//off button clicked
    positionimage14a.y = 410;
    
    positionimage15a.x = 720;//volume slider
    positionimage15a.y = 520;
    
    positionimage16a.x = 560+100;//on button clicked
    positionimage16a.y = 410;



//INIT CAS D'ERREURS

    if(Mix_OpenAudio(44100,MIX_DEFAULT_FORMAT,MIX_DEFAULT_CHANNELS,1024)==-1)
    {
        printf("FAIL AUDIO %s\n",Mix_GetError());
    }
    Mix_Music *music;
    music=Mix_LoadMUS("mainmenu.mp3");
    Mix_PlayMusic(music,-1);

// son lors du click

    Mix_Volume(1, MIX_MAX_VOLUME/2);
    Mix_Chunk *son;
    son = Mix_LoadWAV("mouseclick.wav");
    Mix_VolumeChunk(son, MIX_MAX_VOLUME/2);


// INIT VIDEO

    ecran = SDL_SetVideoMode(1440,900, 32, SDL_HWSURFACE|SDL_DOUBLEBUF);
    SDL_WM_SetCaption("MY GAME", NULL);
//VERIF
    if( ecran == NULL )
    {
        printf( "Can't set video mode: %s \n", SDL_GetError( ) );
        return EXIT_FAILURE;
    }
    imageDeFond1 = IMG_Load("intro/frame_000_delay-0.05s.png"); //background1
    imageDeFond = IMG_Load("background.png"); //background
    if (imageDeFond==NULL) printf(" loading error !  %s \n", SDL_GetError( ));
    else
    {
        SDL_BlitSurface(imageDeFond1, NULL, ecran, &positionFond1);
    

    }

//MENU BUTTONS 

    image1 = IMG_Load("play.png");
    SDL_BlitSurface(image1, &positionFond, ecran, &positionimage1);


    image2 = IMG_Load("settings.png");

    SDL_BlitSurface(image2,&positionFond, ecran, &positionimage2);


    image3 = IMG_Load("quit.png");

    SDL_BlitSurface(image3,&positionFond,ecran,&positionimage3);

    image1a = IMG_Load("play1.png");

    SDL_BlitSurface(image1a,&positionFond,ecran,&positionimage1a);

    image2a = IMG_Load("settings1.png");

    SDL_BlitSurface(image2a,&positionFond,ecran,&positionimage2a);


    image3a = IMG_Load("quit1.png");

    SDL_BlitSurface(image3a,&positionFond,ecran,&positionimage3a);

    image4 = IMG_Load("image4.png"); //game background

    image6 = IMG_Load("image6.png"); // game

    image5 = IMG_Load("image5.png"); // option background


    image10=IMG_Load("image10.png"); //back to main menu

    image12=IMG_Load("image12.png"); // full screen

    image13=IMG_Load("image13.png"); //reduced screen

    image14=IMG_Load("image14.png"); // volume -

    image15=IMG_Load("image15.png");

    image16=IMG_Load("image16.png"); //volume +

    image10a=IMG_Load("image10a.png");

    image12a=IMG_Load("image12a.png"); //fscreen selectionné

    image13a=IMG_Load("image13a.png"); // rscreen selectionné

    image14a=IMG_Load("image14a.png");

    image15a=IMG_Load("image15a.png");

    image16a=IMG_Load("image16a.png");

    SDL_Event event;

    int done =1,n=0;
    int k=0,etat=0,s=0,v=64,counterr=0;
char animation[50];
///////////////////////////////////////////
char intro[50];
  int c=0;



  // intro : 

while (c<18) 
    {
            
            
	SDL_BlitSurface(imageDeFond1,NULL,ecran,&positionFond1);




	if(c<18)
	{
	sprintf(intro,"intro/frame_00%d_delay-0.05s.png",c);
	SDL_Delay(50);
	imageDeFond1 = IMG_Load(intro);
	}

	if(c>=18)
	{
		sprintf(intro,"intro/frame_00%d_delay-0.05s.png",c);
	SDL_Delay(50);
	imageDeFond1 = IMG_Load(intro);
	}
c++;
        SDL_Flip(ecran);

}
    SDL_FreeSurface(imageDeFond1);

////////////////////////////////////////////
SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond);

//done=0 means exit  et k designe le choix selectionnee
//animation
    while(done)
    {
        if(etat==0)
        {
            
            
	SDL_BlitSurface(imageDeFond,NULL,ecran,&positionFond);




	if(counterr<=32)
	{
	sprintf(animation,"animation/ASSET_0000%d.png",counterr);
	SDL_Delay(0);
	imageDeFond = IMG_Load(animation);
	}

	if(counterr>=32)
	{
		counterr=0;
	}
	counterr++;

                TTF_Init();
                SDL_Color red= {255,255,255};
                TTF_Font* police=NULL;
                police=TTF_OpenFont("font1.ttf",50);
                title=TTF_RenderText_Solid(police,"THE LION OF THE MOUTAIN",red);
                SDL_BlitSurface(title,&positionFond,ecran,&positiontitle);
                TTF_CloseFont(police);
                TTF_Quit();


//ANIMATION 




            if (k==0)   						//plain menu
            {
                SDL_BlitSurface(image1,&positionFond,ecran,&positionimage1);
                SDL_BlitSurface(image2,&positionFond,ecran,&positionimage2);
                SDL_BlitSurface(image3,&positionFond,ecran,&positionimage3);
                SDL_BlitSurface(title,&positionFond,ecran,&positiontitle);




            }
            if(k==1)						// menu play selectionée
            {
                SDL_BlitSurface(image1a,&positionFond,ecran,&positionimage1a);
                SDL_BlitSurface(image2,&positionFond,ecran,&positionimage2);
                SDL_BlitSurface(image3,&positionFond,ecran,&positionimage3);
                SDL_BlitSurface(title,&positionFond,ecran,&positiontitle);

                TTF_Init();
                SDL_Color red= {255,255,255};
                TTF_Font *police=NULL;
                police=TTF_OpenFont("font.ttf",30);
                image8=TTF_RenderText_Solid(police,"click to start the game",red);
                SDL_BlitSurface(image8,&positionFond,ecran,&positionimage8);
                TTF_CloseFont(police);
                TTF_Quit();





            }
            else if (k==2)			// menu parametres selectionée
            {
                SDL_BlitSurface(image1,&positionFond,ecran,&positionimage1);
                SDL_BlitSurface(image2a,&positionFond,ecran,&positionimage2a);
                SDL_BlitSurface(image3,&positionFond,ecran,&positionimage3);
                SDL_BlitSurface(title,&positionFond,ecran,&positiontitle);

                TTF_Init();
                SDL_Color red= {255,255,255};
                TTF_Font* police=NULL;
                police=TTF_OpenFont("font.ttf",30);
                image11=TTF_RenderText_Solid(police,"click to access settings ",red);
                SDL_BlitSurface(image11,&positionFond,ecran,&positionimage11);
                TTF_CloseFont(police);
                TTF_Quit();


            }

            else if (k==3) 			//quit selectionée
            {
                SDL_BlitSurface(image1,&positionFond,ecran,&positionimage1);
                SDL_BlitSurface(image2,&positionFond,ecran,&positionimage2);
                SDL_BlitSurface(image3a,&positionFond,ecran,&positionimage3a);
                SDL_BlitSurface(image11a,&positionFond,ecran,&positionimage11a);
                SDL_BlitSurface(title,&positionFond,ecran,&positiontitle);
                TTF_Init();
                SDL_Color red= {255,255,255};
                TTF_Font* police=NULL;
                police=TTF_OpenFont("font.ttf",30);
                image11a=TTF_RenderText_Solid(police,"click to exit ",red);


                TTF_CloseFont(police);
                TTF_Quit();

            }

            while(SDL_PollEvent(&event))
            {

                switch(event.type)
                {
                case SDL_QUIT:
                    done = 0;

                    break;
                case SDL_KEYDOWN:
                {


                    if(event.key.keysym.sym == SDLK_ESCAPE)
                    {
                        ecran = SDL_SetVideoMode(1440,900, 32, SDL_HWSURFACE|SDL_DOUBLEBUF);
                        putenv("SDL_VIDEO_CENTERED=1");

                    }
                    else if (event.key.keysym.sym == SDLK_UP)
                    {
                        if (k==0)
                            k=3;
                        else if (k==1)
                        {
                            k=3;
                        }
                        else
                        {
                            k--;
                        }
                    }

                    else if (event.key.keysym.sym == SDLK_DOWN)
                    {
                        if (k==0) // k means nb de case max=3 buttons
                            k=1;
                        else if (k==3)
                        {
                            k=1;
                        }
                        else
                        {
                            k++;
                        }
                    }
                    else if ((event.key.keysym.sym == SDLK_SPACE)||(event.key.keysym.sym == SDLK_RETURN))
                    {
                        if (k==1)
                        {
                            SDL_BlitSurface(image6,&positionFond,ecran,&positionimage6);
                            SDL_Flip(ecran);
                            Mix_PlayChannel(-1,son,0);
                            SDL_Delay(5000);
                        }
                        else if (k==2)
                        {
                            etat=1;
                            Mix_PlayChannel(-1,son,0);
                        }

                        else if (k==3)
                        {
                            done=0;
                            Mix_PlayChannel(-1,son,0);
                        }


                    }
                
                    break;
                case SDLK_ESCAPE:
                    exit(EXIT_SUCCESS);
                    break;
                }	//case;

                case SDL_MOUSEBUTTONDOWN: //mouse
                {
                    if (event.button.button ==SDL_BUTTON_LEFT)
                    {
                        positionclic.x=event.button.x;
                        positionclic.y =event.button.y;
                        if (event.button.x>positionimage1.x && event.button.x<positionimage1.x+positionimage1.w && event.button.y>positionimage1.y && event.button.y<positionimage1.y+positionimage1.h)
                        {
                            etat=2;
                            Mix_PlayChannel(-1,son,0);	 //game

                        }

                        else if (event.button.x>positionimage2.x && event.button.x<positionimage2.x+positionimage2.w && event.button.y>positionimage2.y && event.button.y<positionimage2.y+positionimage2.h)//option
                        {
                            etat=1; // menu option
                            Mix_PlayChannel(-1,son,0);

                        }
                        else if (event.button.x>positionimage3.x && event.button.x<positionimage3.x+positionimage3.w && event.button.y>positionimage3.y && event.button.y<positionimage3.y+positionimage3.h)//exit
                        {
                            done=0; //exit
                            Mix_PlayChannel(-1,son,0);
                        }



                    }//if

                }//case
                case SDL_MOUSEMOTION: // when the user moves the mouse
                {
                    //init
                    positionclic.x=event.motion.x;
                    positionclic.y =event.motion.y;

                    if (event.motion.x>positionimage1.x && event.motion.x<positionimage1.x+positionimage1.w && event.motion.y>positionimage1.y && event.motion.y<positionimage1.y+positionimage1.h)  //jouer
                    {
                        k=1;

                    }

                    else if (event.motion.x>positionimage2.x && event.motion.x<positionimage2.x+positionimage2.w && event.motion.y>positionimage2.y && event.motion.y<positionimage2.y+positionimage2.h)    //option
                    {
                        k=2;


                    }
                    else if (event.motion.x>positionimage3.x && event.motion.x<positionimage3.x+positionimage3.w && event.motion.y>positionimage3.y && event.motion.y<positionimage3.y+positionimage3.h)  //exit
                    {

                        k=3;
                    }

                    else k=0;


                }//fincase


                }//finswitch


            }
        }
        else if(etat==2)
        {
            SDL_BlitSurface(image4,&positionFond,ecran,&positionimage4);      
        }
        else if(etat==1)
        {
            SDL_BlitSurface(image5,&positionFond,ecran,&positionimage5);
            if (s==0)
            {
                SDL_BlitSurface(image10,&positionFond,ecran,&positionimage10);
                SDL_BlitSurface(image12,&positionFond,ecran,&positionimage12);
                SDL_BlitSurface(image13,&positionFond,ecran,&positionimage13);
                SDL_BlitSurface(image14,&positionFond,ecran,&positionimage14);
                SDL_BlitSurface(image15,&positionFond,ecran,&positionimage15);
                SDL_BlitSurface(image15a,&positionFond,ecran,&positionimage15a);
                SDL_BlitSurface(image16,&positionFond,ecran,&positionimage16);
            }
            else if(s==1)
            {
                SDL_BlitSurface(image10a,&positionFond,ecran,&positionimage10a);
                SDL_BlitSurface(image12,&positionFond,ecran,&positionimage12);
                SDL_BlitSurface(image13,&positionFond,ecran,&positionimage13);
                SDL_BlitSurface(image14,&positionFond,ecran,&positionimage14);
                SDL_BlitSurface(image15,&positionFond,ecran,&positionimage15);
                SDL_BlitSurface(image15a,&positionFond,ecran,&positionimage15a);
                SDL_BlitSurface(image16,&positionFond,ecran,&positionimage16);


            }
            else if(s==2)
            {
                SDL_BlitSurface(image10,&positionFond,ecran,&positionimage10);
                SDL_BlitSurface(image12a,&positionFond,ecran,&positionimage12a);
                SDL_BlitSurface(image13,&positionFond,ecran,&positionimage13);
                SDL_BlitSurface(image14,&positionFond,ecran,&positionimage14);
                SDL_BlitSurface(image15,&positionFond,ecran,&positionimage15);
                SDL_BlitSurface(image15a,&positionFond,ecran,&positionimage15a);
                SDL_BlitSurface(image16,&positionFond,ecran,&positionimage16);

            }
            else if(s==3)
            {
                SDL_BlitSurface(image10,&positionFond,ecran,&positionimage10);
                SDL_BlitSurface(image12,&positionFond,ecran,&positionimage12);
                SDL_BlitSurface(image13a,&positionFond,ecran,&positionimage13a);
                SDL_BlitSurface(image14,&positionFond,ecran,&positionimage14);
                SDL_BlitSurface(image15,&positionFond,ecran,&positionimage15);
                SDL_BlitSurface(image15a,&positionFond,ecran,&positionimage15a);
                SDL_BlitSurface(image16,&positionFond,ecran,&positionimage16);

            }
            else if(s==4)
            {
                SDL_BlitSurface(image10,&positionFond,ecran,&positionimage10);
                SDL_BlitSurface(image12,&positionFond,ecran,&positionimage12);
                SDL_BlitSurface(image13,&positionFond,ecran,&positionimage13);
                SDL_BlitSurface(image14a,&positionFond,ecran,&positionimage14a);
                SDL_BlitSurface(image15,&positionFond,ecran,&positionimage15);
                SDL_BlitSurface(image15a,&positionFond,ecran,&positionimage15a);
                SDL_BlitSurface(image16,&positionFond,ecran,&positionimage16);

            }
            else if(s==5)
            {
                SDL_BlitSurface(image10,&positionFond,ecran,&positionimage10);
                SDL_BlitSurface(image12,&positionFond,ecran,&positionimage12);
                SDL_BlitSurface(image13,&positionFond,ecran,&positionimage13);
                SDL_BlitSurface(image14,&positionFond,ecran,&positionimage14);
                SDL_BlitSurface(image15,&positionFond,ecran,&positionimage15);
                SDL_BlitSurface(image15a,&positionFond,ecran,&positionimage15a);
                SDL_BlitSurface(image16a,&positionFond,ecran,&positionimage16a);

            }

            while(SDL_PollEvent(&event))
            {
                switch(event.type)
                {
                case SDL_QUIT:
                    done = 0;

                    break;
                case SDL_KEYDOWN:
                {


                    if(event.key.keysym.sym == SDLK_ESCAPE)
                    {
                        exit(EXIT_SUCCESS);

                    }
                    else if (event.key.keysym.sym == SDLK_LEFT)
                    {
                        v-=5;
                        Mix_VolumeMusic(v);
                        positionimage15a.x-=15;
                        if (positionimage15a.x<=630)
                            positionimage15a.x=630;

                    }
                    else if (event.key.keysym.sym == SDLK_RIGHT)
                    {
                        v+=5;
                        Mix_VolumeMusic(v);
                        positionimage15a.x+=15;
                        if (positionimage15a.x>=920)
                            positionimage15a.x=910;
                    }
                }
                case SDL_MOUSEBUTTONDOWN:
                {
                    if (event.button.button ==SDL_BUTTON_LEFT)
                    {
                        positionclic.x=event.button.x;
                        positionclic.y =event.button.y;
                        if (event.button.x>positionimage12.x && event.button.x<positionimage12.x+positionimage12.w && event.button.y>positionimage12.y && event.button.y<positionimage12.y+positionimage12.h)
                        {
                            putenv("SDL_VIDEO_CENTERED=1");
                            ecran = SDL_SetVideoMode(1720,950, 32, SDL_HWSURFACE|SDL_DOUBLEBUF|SDL_FULLSCREEN);
                            Mix_PlayChannel(-1,son,0);
                        }

                        else if (event.button.x>positionimage13.x && event.button.x<positionimage13.x+positionimage13.w && event.button.y>positionimage13.y && event.button.y<positionimage13.y+positionimage13.h)
                        {
                            putenv("SDL_VIDEO_CENTERED=1");
                            ecran = SDL_SetVideoMode(1440,900, 32, SDL_HWSURFACE|SDL_DOUBLEBUF);
                            Mix_PlayChannel(-1,son,0);

                        }
                        else if (event.button.x>positionimage14.x && event.button.x<positionimage14.x+positionimage14.w && event.button.y>positionimage14.y && event.button.y<positionimage14.y+positionimage14.h)
                        {
                            v=0;
                            Mix_VolumeMusic(v);
                            positionimage15a.x=580+50;
                            Mix_PlayChannel(-1,son,0);
                        }
                        else if (event.button.x>positionimage16.x && event.button.x<positionimage16.x+positionimage16.w && event.button.y>positionimage16.y && event.button.y<positionimage16.y+positionimage16.h)
                        {
                            v=128;
                            Mix_VolumeMusic(v);
                            positionimage15a.x=720+200;
                            Mix_PlayChannel(-1,son,0);

                        }
                        else if (event.button.x>positionimage10.x && event.button.x<positionimage10.x+positionimage10.w && event.button.y>positionimage10.y && event.button.y<positionimage10.y+positionimage10.h)
                        {
                            etat=0;
                            Mix_PlayChannel(-1,son,0);
                        }
                        else if (event.button.x>positionimage15a.x && event.button.x<positionimage15a.x+positionimage15a.w && event.button.y>positionimage15a.y && event.button.y<positionimage15a.y+positionimage15a.h)
                        {
                            n=1;
                            Mix_PlayChannel(-1,son,0);
                        }
                        break;
                        case SDL_MOUSEBUTTONUP:
                            n=0;
                            break;



                        }//if

                    }//case
                case SDL_MOUSEMOTION:
                {
                    positionclic.x=event.motion.x;
                    positionclic.y =event.motion.y;
                    if (event.motion.x>positionimage12.x && event.motion.x<positionimage12.x+positionimage12.w && event.motion.y>positionimage12.y && event.motion.y<positionimage12.y+positionimage12.h)
                    {
                        s=2;
                    }

                    else if (event.motion.x>positionimage13.x && event.motion.x<positionimage13.x+positionimage13.w && event.motion.y>positionimage13.y && event.motion.y<positionimage13.y+positionimage13.h)
                    {
                        s=3;
                    }
                    else if (event.motion.x>positionimage14.x && event.motion.x<positionimage14.x+positionimage14.w && event.motion.y>positionimage14.y && event.motion.y<positionimage14.y+positionimage14.h)
                    {
                        s=4;
                    }
                    else if (event.motion.x>positionimage16.x && event.motion.x<positionimage16.x+positionimage16.w && event.motion.y>positionimage16.y && event.motion.y<positionimage16.y+positionimage16.h)
                    {
                        s=5;
                    }
                    else if (event.motion.x>positionimage10.x && event.motion.x<positionimage10.x+positionimage10.w && event.motion.y>positionimage10.y && event.motion.y<positionimage10.y+positionimage10.h)
                    {
                        s=1;
                        
                    }
                    else s=0;


                    if (n==1)
                    {
                        if (positionimage15a.x>200 &&positionimage15a.x<930 )
                        {


                            positionimage15a.x+=event.motion.xrel;
                            v+=event.motion.xrel;
                            Mix_VolumeMusic(v);
                            if (positionimage15a.x<=630)
                                positionimage15a.x=630;
                            else if (positionimage15a.x>=920)
                                positionimage15a.x=920;
                        }
                    }






                }//case


                }//switch

            }//while



        }
        SDL_Flip(ecran);
    }//while




    SDL_FreeSurface(imageDeFond);
    SDL_FreeSurface(image1);
    SDL_FreeSurface(image2);
    SDL_FreeSurface(image3);
    SDL_FreeSurface(image4);
    SDL_FreeSurface(image5);
    SDL_FreeSurface(image6);
    SDL_FreeSurface(image1a);
    SDL_FreeSurface(image2a);
    SDL_FreeSurface(image3a);

    SDL_Quit();

    return EXIT_SUCCESS;
}
