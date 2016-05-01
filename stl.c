// Binary STL file parser created by Sivesh Selvakumar
// 04/30/2016
// Takes a binary STL file as input and provides a GNUPlot compatible ASCII file
// as output.

#include <stdio.h>

// Define a structure for storing the information associated with each triangular
// facet of the STL file. This is a 50 byte structure.

struct facet{
  float nx, ny, nz; // 4 byte floats for each coordinate of the normal
  float v1x, v1y, v1z; //4 byte floats for each coordinate of vertex 1
  float v2x, v2y, v2z; //4 byte floats for each coordinate of vertex 2
  float v3x, v3y, v3z; //4 byte floats for each coordinate of vertex 3
  //short int spacer; // 2 byte spacer
};

// Begin main program

int main(int argc, char *argv[]) {

  char *filename;
  switch (argc) {
    case 1:
      printf("Enter one filename to be parsed \n");
      break;
    case 2:
      filename = argv[1]; //assign filename
      break;
    default:
      printf("Enter only one filename to be parsed \n");
      break;
  }

    printf("The entered filename is: %s \n",filename);

  // Create file pointers for the input and output files
  FILE *ptr_inputfile;
  FILE *ptr_outputfile;

  // Open the files for read in binary and write in ASCII respectively.
  // If either file does not open, we exit the program with an error.
  ptr_inputfile = fopen(filename,"rb");
  if (!ptr_inputfile) {
    printf("Unable to open input file\n");
    return 1;
  }

  ptr_outputfile = fopen("gnu_plot_output.dat","w");
  if (!ptr_outputfile) {
    printf("Unable to open output file\n");
    return 1;
  }

  fseek(ptr_inputfile,80,SEEK_SET); //Skip the 80 byte header
  unsigned int number_of_facets; //Initialize an unsigned int to store the number of facets
  fread(&number_of_facets, sizeof(number_of_facets), 1, ptr_inputfile); // Read the 4-byte integer with the number of facets
  printf("The number of facets is: %d\n",number_of_facets);

  struct facet current_facet; //Initialize a variable to hold the current facet

  // Read each facet one by one and write the vertex coordinates alone to an
  // ASCII file

  for (int i=1;i<=number_of_facets;i++) {
    // Read the current facet into the structure
    fread(&current_facet, sizeof(current_facet),1, ptr_inputfile);

    // Write the ASCII representations of the facet to the text file with a
    // newline between each facet
    fprintf(ptr_outputfile, "%f %f %f\n", current_facet.v1x, current_facet.v1y, current_facet.v1z);
    fprintf(ptr_outputfile, "%f %f %f\n", current_facet.v2x, current_facet.v2y, current_facet.v2z);
    fprintf(ptr_outputfile, "%f %f %f\n", current_facet.v3x, current_facet.v3y, current_facet.v3z);
    fprintf(ptr_outputfile, "\n");

    // Skip the 2 byte spacer between each facet
    fseek(ptr_inputfile,2,SEEK_CUR);
  }

  // Close the file handles and release memory back to the OS
  fclose(ptr_inputfile);
  fclose(ptr_outputfile);

}
