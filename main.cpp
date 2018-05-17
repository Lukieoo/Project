#include<allegro5/allegro.h>
#include<allegro5/allegro_image.h>
#include<allegro5/allegro_primitives.h>
#include<windows.h>
#include<iostream>
#include<allegro5/allegro_native_dialog.h>
#include <allegro5/allegro_font.h>
#include<allegro5/allegro_audio.h>
#include<allegro5/allegro_acodec.h>
#include <allegro5/allegro_ttf.h>
#include <time.h>
#include <cstdlib>




using namespace std;
class cPtak
{
    public:
        int x, y;
        int x2,y2;


        cPtak() :
        x(  300 ),
        y(  450 ),
        x2( 48  ),
        y2( 38  )
        {

        }
};

class cprzeszkoda
{
    public:
        int x;
        int y;
        int x2;
        int y2;

};

int ran=0;
int ra=0;
int punkty=0;
int punktydz=0;
int przycisk=0;
int main()
{

HWND okno = FindWindowA( "ConsoleWindowClass", NULL );
ShowWindow( okno, SW_HIDE );

      ALLEGRO_USTR * Tekst  = al_ustr_new("0");
    ALLEGRO_USTR * Tekst2  = al_ustr_new("0");
    for( ; ; )
{
przycisk=0;
    al_init_font_addon();
    al_init_ttf_addon();
    al_init();
    al_init_image_addon();
    al_init_primitives_addon();
    al_install_audio();
    al_init_acodec_addon();
    al_install_keyboard();
    al_install_mouse();


    ALLEGRO_KEYBOARD_STATE klawisz;
    ALLEGRO_MOUSE_STATE    mysz;
    ALLEGRO_MOUSE_STATE    ty;
    ALLEGRO_DISPLAY *Ekran;
    Ekran = al_create_display( 1200, 800 );
    al_set_window_title( Ekran, "Flapy BETA" );


    ALLEGRO_FONT *font_ttf    = al_load_ttf_font("courbd.ttf",100, 0);

    ALLEGRO_SAMPLE *soundEffect = al_load_sample("sound1.wav");
    al_reserve_samples(1);




    al_set_new_bitmap_flags ( ALLEGRO_MIN_LINEAR | ALLEGRO_MAG_LINEAR);

    ALLEGRO_BITMAP  *obrazek = al_load_bitmap( "Tlo.jpg" );
    ALLEGRO_BITMAP  *obrazek2 = al_load_bitmap( "Tlo2.jpg" );
    ALLEGRO_BITMAP  *ptaszek = al_load_bitmap( "Ptaszek.png" );
    ALLEGRO_BITMAP  *tunel1 = al_load_bitmap( "tunel1.png" );
    ALLEGRO_BITMAP  *Trawa = al_load_bitmap( "Trawa.png" );
    ALLEGRO_BITMAP  *menu = al_load_bitmap( "menu.jpg" );




    int licznik_klatek = 0;


    float szybkosc_tla  = 0.5f;
    float przesow_tla_1 = 0.0f;
    float przesow_tla_2 = 1200.0f;


    cPtak Ptak;
    cprzeszkoda Blok;
    Blok.x=1200;
    Blok.y=635;
    Blok.x2=83;
    Blok.y2=130;
    cprzeszkoda Blo;
    Blo.x=1200;
    Blo.y=80;
    Blo.x2=83;
    Blo.y2=130;

    cprzeszkoda Bl;
    Bl.x=1900;
    Bl.y=80;
    Bl.x2=83;
    Bl.y2=130;

    cprzeszkoda B;
    B.x=1900;
    B.y=635;
    B.x2=83;
    B.y2=130;



    cprzeszkoda trawa;
    trawa.x=0;
    trawa.y=750;

    cprzeszkoda trawa_2;
    trawa_2.x=1200;
    trawa_2.y=750;


    float przysp = 0;


    for(;;)
{///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    al_get_keyboard_state( &klawisz );

    al_draw_bitmap( menu, 0, 0, 0 );

    al_draw_ustr(font_ttf,al_map_rgb (0,0,0), 570, 310, 0,Tekst);
    al_draw_ustr(font_ttf,al_map_rgb (0,0,0), 520, 310, 0,Tekst2);
    al_get_mouse_state( &mysz );

    int mx = mysz.x;
    int my = mysz.y;

    al_draw_filled_circle( mx , my ,15, al_map_rgb( 205, 0, 0 ) );

    if( 460 < mx && mx < 700 &&
        620 < my && my < 700 )
    {
        if( mysz.buttons == 1)
        {
            exit(0);
             //   al_draw_filled_rectangle( 450, 620,
                       //     700, 700,
                      //   al_map_rgb( 255, 0, 0 ) );
        }
        else
        {
            al_draw_rectangle( 460, 620,700, 700, al_map_rgb( 240, 100, 17 ), 1 );
        }
    }

    if( 475 < mx && mx < 675 &&
        485 < my && my < 580 )
    {
        if( mysz.buttons == 1)
        {
              break;
        }
        else
        {
        al_draw_rectangle( 475,485,675, 580, al_map_rgb( 240, 100, 17 ), 1 );
        }
    }
  ///



  if( 1140 < mx && mx < 1150 &&
        745 < my && my < 760 )
    {

            if( mysz.buttons == 1)
            {


                menu = al_load_bitmap( "menu2.jpg" );
                przycisk=1;

            }
            else if (mysz.buttons ==2)
            {
                menu = al_load_bitmap( "menu.jpg" );
                przycisk=0;

            }
        else
        {
           al_draw_circle(1146,752, 30, al_map_rgb(0, 0, 255), 5);
        }
    }
  if( przycisk==1 && 890 < mx && mx < 1161 &&
        224 < my && my < 305 )
    {

        if(mysz.buttons==1)
        {
         obrazek=al_load_bitmap( "super.jpg" );
          obrazek2=al_load_bitmap( "super2.jpg" );
          tunel1=al_load_bitmap( "mariot.jpg" );
          ptaszek=al_load_bitmap( "Hal_copy.png" );
        }

        else
        {
             al_draw_rectangle( 890, 224,1161, 305,al_map_rgb( 240, 100, 17 ), 4 );
        }

    }

    if( przycisk==1 && 890 < mx && mx < 1161 &&
        324 < my && my < 405 )
    {

        if(mysz.buttons==1)
        {
          obrazek=al_load_bitmap( "stone_mapa.jpg" );
          obrazek2=al_load_bitmap( "stone_mapa2.jpg" );
          tunel1=al_load_bitmap( "stone.jpg" );
          ptaszek=al_load_bitmap( "Bomb.png" );
        }

        else
        {
             al_draw_rectangle( 890, 324,1164, 395,al_map_rgb( 240, 100, 17 ), 4 );
        }

    }

      if( przycisk==1 && 890 < mx && mx < 1164 &&

        404 < my && my < 475 )
    {

        if(mysz.buttons==1)
        {
        obrazek=al_load_bitmap( "Tlo.jpg" );
          obrazek2=al_load_bitmap( "Tlo2.jpg" );
          tunel1=al_load_bitmap( "tunel1.png" );
          ptaszek=al_load_bitmap( "Ptaszek.png" );
        }

        else
        {
             al_draw_rectangle( 890, 404,1164, 475,al_map_rgb( 240, 100, 17 ), 4 );
        }

    }


    al_flip_display();


    al_rest( 0.004 );





    if( al_key_down( &klawisz,ALLEGRO_KEY_SPACE ) )
    {
        break;
    }
      if( al_key_down( &klawisz,ALLEGRO_KEY_ESCAPE ) )
    {

        return 0;

    }


 ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
}

punkty=0;
punktydz=0;
        for( ; ; )
    {

    unsigned char Wynik[ 10 ] = "";
    unsigned char Wynikd[ 10 ] = "";

    itoa( punkty, (char*)Wynik, 100 );
    itoa( punktydz, (char*)Wynikd, 100 );

    Tekst->data = Wynik;
    Tekst2->data = Wynikd;


    srand(time(NULL));
    ran=rand()%40;
    ra=rand()%40;
    al_get_keyboard_state( &klawisz );
    al_get_mouse_state( &ty );

    if( al_key_down( &klawisz,ALLEGRO_KEY_ESCAPE ) )
        {
            break;
        }




        if((( (al_key_down( &klawisz, ALLEGRO_KEY_SPACE ))||(ty.buttons == 1))&&( Ptak.y+Ptak.y2  >= 150)))

        {
            przysp = -10.0f;
        }


        if( licznik_klatek %4 == 0 )
        {

            if( Ptak.y+Ptak.y2  >= 770){


                break;

                }



                if( Ptak.y-Ptak.y2 <2)
                {

                  przysp = 6;

                }

            else
            {
                if( Ptak.x +Ptak.x2 > Blok.x - Blok.x2 &&
                    Ptak.x -Ptak.x2 < Blok.x + Blok.x2 &&
                    Ptak.y +Ptak.y2 > Blok.y - Blok.y2+ra &&
                    Ptak.y -Ptak.y2< Blok.y + Blok.y2+ra )
                    {
                     al_play_sample(soundEffect,1.0,0.0,1.0, ALLEGRO_PLAYMODE_ONCE,0);




                   break;

                    }

                if( Ptak.x +Ptak.x2 > Blo.x - Blo.x2 &&
                    Ptak.x -Ptak.x2 < Blo.x + Blo.x2 &&
                    Ptak.y +Ptak.y2 > Blo.y - Blo.y2+ra &&
                    Ptak.y -Ptak.y2< Blo.y + Blo.y2+ra )
                    {

                    al_play_sample(soundEffect,1.0,0.0,1.0, ALLEGRO_PLAYMODE_ONCE,0);
                  break;

                    }
                     if( Ptak.x +Ptak.x2 > B.x - B.x2 &&
                    Ptak.x -Ptak.x2 < B.x + B.x2 &&
                    Ptak.y +Ptak.y2 > B.y - B.y2+ran &&
                    Ptak.y -Ptak.y2< B.y + B.y2+ran )
                    {
                     al_play_sample(soundEffect,1.0,0.0,1.0, ALLEGRO_PLAYMODE_ONCE,0);


                 break;
                    }

                if( Ptak.x +Ptak.x2 > Bl.x - Bl.x2 &&
                    Ptak.x -Ptak.x2 < Bl.x + Bl.x2 &&
                    Ptak.y +Ptak.y2 > Bl.y - Bl.y2+ran&&
                    Ptak.y -Ptak.y2< Bl.y + Bl.y2+ran )
                    {

                    al_play_sample(soundEffect,1.0,0.0,1.0, ALLEGRO_PLAYMODE_ONCE,0);
                    break;

                    }

                else

                    al_draw_bitmap( obrazek, przesow_tla_1, 0, 0 );
                    al_draw_bitmap( obrazek2, przesow_tla_2, 0, 0 );

            }

            Ptak.y += przysp;

        float kat = 3.1415 * przysp / 55.0;

        al_draw_rotated_bitmap(ptaszek, 48, 38, Ptak.x, Ptak.y, kat, 0);
        al_draw_bitmap(tunel1, Blok.x - Blok.x2 , Blok.y - Blok.y2+ra, 0);
        al_draw_bitmap(tunel1, Blo.x - Blo.x2, Blo.y - Blo.y2+ra, 3);

        al_draw_bitmap(tunel1, Bl.x - Bl.x2 , Bl.y - Bl.y2+ran, 3);
        al_draw_bitmap(tunel1, B.x - B.x2 , B.y - B.y2+ran, 0);

        al_draw_bitmap(Trawa, trawa.x, trawa.y , 0);
        al_draw_bitmap(Trawa, trawa_2.x, trawa_2.y , 0);
        al_draw_ustr(font_ttf,al_map_rgb (0,0,20), 55, 40, 0,Tekst);
        al_draw_ustr(font_ttf,al_map_rgb (0,0,20), 10, 40, 0,Tekst2);
        al_flip_display();

        }




        przesow_tla_1 -= szybkosc_tla;
        przesow_tla_2 -= szybkosc_tla;

        licznik_klatek++;

        przysp += 0.1f;


        trawa.x--;
        trawa_2.x--;

        Blok.x--;
        Blo.x--;
        Bl.x--;
        B.x--;

       if(Ptak.x==Blo.x||Ptak.x==B.x)
                {
                    punkty++;


                   if(punkty==10)
                   {
                       punktydz++;
                       punkty=0;
                   }
                   itoa( punkty, (char*)Wynik, 100 );
                   itoa( punktydz, (char*)Wynikd, 100 );
                    Tekst->data = Wynik;
                    Tekst->data = Wynikd;
                }

        if( Blo.x + Blo.x2 < 0 )
        {
            Blo.x = 1200 + Blo.x2;
       ///POkombinowane

         if  (ran=rand()%40<20 )
         {
             ran++;
         }
         else         {
             ran-=10;
         }
         ///
        }

        if( Blok.x + Blok.x2 < 0 )
        {
            Blok.x = 1200 + Blok.x2;
        }

        if( Bl.x + Bl.x2 < 0 )
        {
            Bl.x = 1200 + Bl.x2;
           //ra=rand()%40 ;
        }

        if( B.x + B.x2 <   0 )
        {
            B.x = 1200 + B.x2;
        }




        if( trawa.x <= -1200 )
        {
            trawa.x = 1200;
        }

        if( trawa_2.x <= -1200 )
        {
            trawa_2.x = 1200;
        }

        if( przesow_tla_1 <= -1200 )
        {
            przesow_tla_1 = 1200;
        }

        if( przesow_tla_2 <= -1200 )
        {
            przesow_tla_2 = 1200;
        }

        al_rest( 0.004 );
    }


    punkty=0;
    punktydz=0;

    Sleep(400);




    al_destroy_font(font_ttf);
    al_destroy_bitmap(ptaszek);
    al_destroy_bitmap(tunel1);
    al_destroy_bitmap(Trawa);
    al_destroy_bitmap(obrazek2);
    al_destroy_bitmap(obrazek);
    al_destroy_bitmap(menu);
    al_destroy_display( Ekran );

    al_shutdown_primitives_addon();
    al_destroy_sample(soundEffect);

}
    return 0;
}


