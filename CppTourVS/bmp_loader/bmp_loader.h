#pragma once
#include <iostream>
#include <vector>
#include <map>
#include <memory>

struct Bitmap {
public:
 Bitmap(unsigned int xp,
        unsigned int yp,
        unsigned char R,
        unsigned char G,
        unsigned char B)
  : xp(xp), yp(yp), R(R), G(G), B(B) {
 };
 unsigned int xp;
 unsigned int yp;
 unsigned char R;
 unsigned char G;
 unsigned char B;
};

/*This class can load *.bpm  
images and save them as array of pixels
**/
class BMP_Sprites_Hub {
public:
 BMP_Sprites_Hub() = default;
 // std::map< std::string -> Filename , std::vector<Bitmap> -> Bitmap > Holds all bmp images
 //std::unique_ptr<std::map<std::string, std::vector<Bitmap>>> *sprites_hub = nullptr;

 // Converts bpm file to vector<Bitmap> array
 void  bmp_convert(std::string filename, std::vector<Bitmap>& bitmap) {
  FILE* f;
  fopen_s(&f, filename.c_str(), "r+");

  if (f == nullptr) 
  {
   std::cout << "File not exist!";
   return;
  }
  
 
  unsigned char info[54];
  fread(info, sizeof(unsigned char), 54, f);  // read the 54-byte header

  // extract image height and width from header
  int width = *(int*)&info[18];
  int height = *(int*)&info[22];



  int row_padded = (width * 3 + 3) & (~3);
  unsigned char* data = new unsigned char[row_padded];
  unsigned char tmp;

  for (int i = 0; i < height; i++)
  {
   fread(data, sizeof(unsigned char), row_padded, f);
   for (int j = 0; j < width * 3; j += 3)
   {
    // Convert (B, G, R) to (R, G, B)
    tmp = data[j];
    data[j] = data[j + 2];
    data[j + 2] = tmp;
    if ((int)data[j] != 255 && (int)data[j + 1] != 255 &&
        (int)data[j + 2] != 255)
    {
     Bitmap bm =
      Bitmap(i, j / 3, (int)data[j], (int)data[j + 1], (int)data[j + 2]);
     bitmap.push_back(bm);
    }
   }
  }

 }

};


