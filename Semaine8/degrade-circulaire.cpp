#include <stdexcept>
#include <fstream>
#include <iostream>
#include <math.h>
#include <vector>
using namespace std;

vector<int> HSVtoRGB(float H, float S, float V){
    float s = S/100;
    float v = V/100;
    float C = s*v;
    float X = C*(1-abs(fmod(H/60.0, 2)-1));
    float m = v-C;
    float r,g,b;
    if(H >= 0 && H < 60){
        r = C,g = X,b = 0;
    }
    else if(H >= 60 && H < 120){
        r = X,g = C,b = 0;
    }
    else if(H >= 120 && H < 180){
        r = 0,g = C,b = X;
    }
    else if(H >= 180 && H < 240){
        r = 0,g = X,b = C;
    }
    else if(H >= 240 && H < 300){
        r = X,g = 0,b = C;
    }
    else{
        r = C,g = 0,b = X;
    }
    int R = (r+m)*255;
    int G = (g+m)*255;
    int B = (b+m)*255;
    vector<int> RGB = {R, G, B};
    return RGB;
}


int main() {

    int Size;
    cout << "Taille : ";
    cin >> Size;

    Size += 1 - Size%2;
    
    int Dx = -Size/2;
    int Dy = -Size/2;
    float Max = 100.;
    float Step = Max / sqrt(Dx*Dx + Dy*Dy);
    
    ofstream fichier;
    fichier.open("degrade-circulaire.ppm");
    fichier << "P3" << endl << Size << " " << Size << endl << Max << endl;
    vector<int> RGBCol = {0, 0, 0};
    float Hue, Saturation;
    int X,Y;
    for (int y=0; y<Size; y++) {
        for (int x=0; x<Size; x++) {
            X = x+Dx;
            Y = y+Dy;

            Hue = atan(Y/X) * (180.0/3.1415);
            Saturation = sqrt(X*X + Y*Y);
            
            RGBCol = HSVtoRGB(Hue, Saturation, 80);
            for (auto i:RGBCol) {
                fichier << i << " ";
            }
        }
        fichier << endl;
    }
    fichier.close();
}

