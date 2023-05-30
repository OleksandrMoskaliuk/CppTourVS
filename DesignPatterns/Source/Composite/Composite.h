#pragma once

namespace Composite 
{

 class File 
 {
 public:
  virtual void add_file(File *file) = 0;
   virtual void remove_file(File *file) = 0;
 };

 class Folder : public File 
 {
  public:
   void add_file(File *file) override {};
   void remove_file(File *file) override {};

  private:
 };


}