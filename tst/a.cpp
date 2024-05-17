void sayHi();  // forward declaration for function sayHi, makes sayHi accessible
               // in this file

int main() {
  sayHi();  // call to function defined in another file, linker will connect
            // this call to the function definition

  return 0;
}