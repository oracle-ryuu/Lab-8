/*
  CPSC 223C
  Spring 2015
  CSU Fullerton

  Lab 8: word frequencies in O(n) time

  Authors:Jared Vanotterdykl oracleryuu@csu.fullerton.edu

*/ 

#include <assert.h>
#include <glib.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NOT_FOUND -1

/* Safe estimate of the length of the longest English word. */
#define MAX_WORD_LENGTH 200


void (*GHFunc) printerhelper( gpointer key, gpointer value, gpointer user_data); 

/* This program uses the glib idiom of logging memory allocation
   errors immediately instead of communicating errors through return
   values. */

/* Read the contents of the text file path, count how many times each
   whitespace-separated word appears, then for each distinct word, print one line

   <WORD> <COUNT>

   to standard output, where <WORD> is the non-whitespace characters
   of the word, and <COUNT> is the number of times it appears, which
   must be a positive integer. */


/* Opaque data type for a data structure that tracks the number of
   occurrences of strings. */
void print_word_frequencies(char* path);
/* TODO: Define a data type called WordCounts. It could be a struct or
   a typedef aliast for a pre-existing data type. */
typedef struct WordCounts{ 
  GHashTable *ptr;
}WordCounts;
void WordCounts_destroy(struct WordCounts * self)
{

}



/* Allocate a new word count object. */
WordCounts* word_counts_make();

/* Free a WordCounts object. */
void word_counts_free(WordCounts* wc);

/* If word is already in wc, increment its count by 1. If word is not
   present, add it with a count of 1. */
void word_counts_increment(WordCounts* wc, char* word);

/* If word is in wc, return its frequency count. If word is not in wc,
   return NOT_FOUND. */
int word_counts_lookup(WordCounts* wc, char* word);

/* Print out all the words and counts in wc, using the same format as
   print_word_frequences. */
void word_counts_print(WordCounts* wc);

int main(int argc, char** argv) {
  if (argc != 2) {
    fputs("error: you must supply a filename as an argument\n", stderr);
    return 1;
  }

  print_word_frequencies(argv[1]);

  return 0;
}

void print_word_frequencies(char* path) {
  /* This function is essentially the same as in the lab 5 solution,
     except that it is no longer responsible for checking whether each
     function call failed or succeeded. */

  FILE* f;
  WordCounts* wc;
  char str[MAX_WORD_LENGTH + 1];

  f = fopen(path, "r");
  if (f == NULL) {
    fprintf(stderr, "error: could not open '%s'", path);
    abort();
  }

  wc = word_counts_make();

  fprintf(stderr, "processing '%s'...", path);

  while (fscanf(f, "%s", str) != EOF) {
    word_counts_increment(wc, str);
  }

  fclose(f);

  fprintf(stderr, "done\n");

  word_counts_print(wc);
  
  word_counts_free(wc);
}

WordCounts* word_counts_make() {
  /* TODO: implement this function */

  /* Hint: use g_hash_table_new or g_hash_table_new_full. Each key
     should be a char* C-style string allocated on the heap with a
     glib function. Each value should be a pointer to an int allocated
     on the heap with a glib function. */
  WordCounts *WordVault= gnew(WordCounts, 1);


  WordVault.ptr= g_hash_table_new_full (g_str_hash, g_int_equal, __ ,__);


}

void word_counts_free(WordCounts* wc) {
  /* TODO: implement this function */

  /* Hint: use g_hash_table_destroy, and be certain that each key
     object and value object is freed with a glib function. */

  g_hash_table_destroy(wc);

}

int word_counts_lookup(WordCounts* wc, char* word) {
  /* TODO: implement this function */

  /* Hint: use g_hash_table_lookup */

  printf("s% i%", word, g_hash_table_lookup(wc->ptr,word));


}

void word_counts_increment(WordCounts* wc, char* word) {
  /* TODO: implement this function */

  /* Hint: use g_hash_table_lookup

     If word is already a key in the table, its corresponding value is
     a pointer to an int; increment that int.
     
     Otherwise allocate new key and value objects using glib
     allocation functions, and use g_hash_table_insert to add them to
     the table.
  */
  if(g_hash_table_lookup( wc->ptr, word)!=NUll){
    int* i;
    //todo create and allocate string pointer, making it equal to word
    i=gnew(int,1);
    *i=g_hash_table_lookup(wc->ptr,word);
    *i++;
    g_hash_table_insert(wc->ptr, word, i)
      }
  else{ g_hash_table_insert(wc->ptr, word, 1)
      }



  
}
void  printhelper (gpointer key,gpointer value, gpointer user_data)
{
  printf("s% i%", key, value);
}
void word_counts_print(WordCounts* wc) {
  /* TODO: implement this function */

  /* Hint: use g_hash_table_foreach or the g_hash_table_iter functions. */
  g_hash_table_foreach( wc->ptr, printhelper, NULL);
}

