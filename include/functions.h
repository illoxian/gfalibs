//
//  functions.h
//
//
//  Created by Giulio Formenti on 12/30/21.
//

#ifndef FUNCTIONS_H
#define FUNCTIONS_H

std::istream& getline(std::istream& is, std::string& str);

std::istream& getline(std::istream& is, std::string& str, char dlm);

double elapsedTime(); // compute runtime in verbose mode

bool checkTag(const char tag1[2], std::string tag2);

bool isInt(const std::string &str);

double gfa_round(double d, uint32_t to=2);

std::vector<unsigned int> intervalSizes(std::vector<unsigned int> &intervalVec);

std::string output(std::string output); // use tab delimiter if tabular flag is true

bool isDash(char * optarg); // check if user input is dash (substitute of input from pipe)

bool ifFileExists(const char * optarg); // check if file exists

void textWrap(std::string input, std::ostream& output, int width); // generic text wrapper (useful for fasta output)

std::string rmFileExt(const std::string path); // utility to strip file extension from file

std::string getFileExt(std::string fileName); // utility to get file extension

std::string revCom(std::string seq); // reverse complement

std::string rev(std::string seq); // reverse string

std::vector<std::string> readDelimited(std::string line, std::string delimiter, std::string skipLine = ""); // read line delimited by specific character, optionally skip lines starting with specific string

std::vector<std::string> readDelimitedArr(std::string line, std::vector<char> delimiters, std::string skipLine = "", bool keepDelimiter = false); // read line delimited by specific character(s), optionally skip lines starting with specific string and keep the delimeter as last character for further processing

bool isNumber(const std::string& str);

void revComPathComponents(std::vector<PathComponent>& pathComponents);

// bed coords are bed coords of compressed sequence
void homopolymerCompress(std::string *sequence, std::vector<std::pair<unsigned long long int, unsigned long long int>> &bedCoords, unsigned int cutoff);

// bed coords are bed coords of compressed sequence
void homopolymerDecompress(std::string *sequence, const std::vector<std::pair<unsigned long long int, unsigned long long int>> &bedCoords);

unsigned int homopolymerRunsCount(const std::string &sequence, unsigned int threshhold);

// bed coords of uncompressed sequence
void homopolymerBedCoords(std::string *sequence, std::vector<std::pair<unsigned int, unsigned int>> &bedCoords, unsigned int cutoff);

void computeNstars(std::vector<unsigned long long int>& lens, // compute N/L* statistics, vector of all lengths
                   std::vector<unsigned long long int>& Nstars,      std::vector<unsigned int>& Lstars, // required arguments are passed by reference
                   std::vector<unsigned long long int>* NGstars = NULL, std::vector<unsigned int>* LGstars = NULL, unsigned long long int gSize = 0);

void rmChrFromStr(std::string &str, const char* charsToRemove);

#endif /* FUNCTIONS_H */
