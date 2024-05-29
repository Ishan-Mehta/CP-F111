#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

/**
 * @brief Returns the appropriate index for the given ASCII character in the ASCII to Braille map. Indexes 0-25 for letters 'a'-'z', 0-8 for digits '1'-'9', index 9 for digit '0', 26 for ' ' (SPACE), and -1 for all other characters (that our translator does not handle).
 *
 */
int map_index(char c)
{
  int ans = -1;
  if (c >= 'a' && c <= 'z')
    ans = c - 'a';
  else if (c >= '1' && c <= '9')
    ans = c - '1';
  else if (c == '0')
    ans = 9;
  else if (c == ' ')
    ans = 26;
  return ans;
}

/**
 * @brief Reports whether the given character can be translated to a Braille symbol. For this program, only consider alphabets, digits, and the SPACE character.
 *
 */
int can_translate_to_braille(char ch)
{
  return isalnum(ch) || ch == ' ';
}

/**
 * @brief Return the string representing the given ASCII character in the given ASCII-to-Braille map.
 *
 * Requires: `ch` can be translated to Braille and map is properly populated.
 *
 */
char *ascii_to_braille(char ch, char *map[])
{
  return map[map_index(ch)];
}

/**
 * @brief Put the Braille-equivalent of the given character using the given map on the given file, if the character can be translated to Braille; ignores otherwise.
 *
 * Requires: fp is opened for writing and map is properly populated
 *
 */
void fputc_braille(char ch, FILE *fp, char *map[])
{
  if (can_translate_to_braille(ch))
  {
    char *b = ascii_to_braille(tolower(ch), map);
    fprintf(fp, "%c%c\n%c%c\n%c%c\n", b[0], b[3], b[1], b[4], b[2], b[5]);
    fputs("\n", fp);
  }
}

/**
 * @brief Adds a dot in the given Braille representation at the given position (indexing for the position starts at 1 in Braille; your representation may start at 0.)
 *
 */
void add_dot_at_pos(char *b, int pos)
{
  b[pos - 1] = '.';
}

/**
 * @brief Creates and returns the ASCII-to-Braille map as described.
 *
 */
char **generate_map()
{
  const int MAP_LENGTH = 27, ENCODING_LENGTH = 7;
  char **m = calloc(MAP_LENGTH, sizeof(char *));
  for (int i = 0; i < MAP_LENGTH; ++i)
    m[i] = calloc(ENCODING_LENGTH, sizeof(char));

  /* hard-coding the first decade (and SPACE) */
  strcpy(m[map_index('a')], ".-----");
  strcpy(m[map_index('b')], "..----");
  strcpy(m[map_index('c')], ".--.--");
  strcpy(m[map_index('d')], ".--..-");
  strcpy(m[map_index('e')], ".---.-");
  strcpy(m[map_index('f')], "..-.--");
  strcpy(m[map_index('g')], "..-..-");
  strcpy(m[map_index('h')], "..--.-");
  strcpy(m[map_index('i')], "-.-.--");
  strcpy(m[map_index('j')], "-.-..-");
  strcpy(m[map_index(' ')], "------");

  /* deriving the second decade by adding a dot at position 3 */
  for (char c = 'k'; c <= 't'; ++c)
  {
    char from = c - 10;
    strcpy(m[map_index(c)], m[map_index(from)]);
    add_dot_at_pos(m[map_index(c)], 3);
  }

  /* deriving the third decade by adding a dot at position 6 and handling special cases */
  for (char c = 'u'; c <= 'z'; ++c)
  {
    char from = c - 10;
    if (c == 'w')
      from = 'j';
    else if (c == 'x' || c == 'y' || c == 'z')
      from = from - 1;
    strcpy(m[map_index(c)], m[map_index(from)]);
    add_dot_at_pos(m[map_index(c)], 6);
  }

  return m;
}

/**
 * @brief Free the heap memory held by the map.
 *
 */
void release_map(char **m)
{
  const int MAP_LENGTH = 27;
  for (int i = 0; i < MAP_LENGTH; ++i)
    free(m[i]);
  free(m);
}

/**
 * @brief Displays the given ASCII-to-Braille map on the console.
 *
 */
void display_map(char *m[])
{
  for (char c = 'a'; c <= 'z'; ++c)
    printf("%c - %s\n", c, m[map_index(c)]);

  for (char c = '0'; c <= '9'; ++c)
    printf("%c - %s\n", c, m[map_index(c)]);

  printf("%c - %s\n", ' ', m[map_index(' ')]);
}

/**
 * @brief Displays the contents of the given text file on the console.
 *
 * Requires: fp is opened for reading
 *
 */
void display_textfile(FILE *fp)
{
  rewind(fp); // ensures you will read from the start
  int c = fgetc(fp);
  while (c != EOF)
  {
    printf("%c", c);
    c = fgetc(fp);
  }
}

/**
 * @brief Returns a FILE's handle after opening it in the given mode. Keeps prompting the user for a valid path otherwise.
 *
 */
FILE *open_file_given_mode(char *mode)
{
  char fname[20];
  printf("Enter valid path: ");
  scanf("%s", fname);
  FILE *fp;
  while (!(fp = fopen(fname, mode)))
  {
    printf("Cannot open %s; Enter valid file path again: ", fname);
    scanf("%s", fname);
  }
  return fp;
}

/**
 * @brief Translates the contents of the given ASCII file to the Braille file using the given character map.
 *
 * Requires: fp_ascii is opened for reading, fp_braille is opened for writing, and map is properly populated
 *
 */
void translate_ascii_to_braille(FILE *fp_ascii, FILE *fp_braille, char *map[])
{
  int c = fgetc(fp_ascii);
  while (c != EOF)
  {
    fputc_braille(c, fp_braille, map);
    c = fgetc(fp_ascii);
  }
}

int main()
{
  char **map = generate_map();
  // display_map(map); // uncomment only to DEBUG

  printf("This program supports two operations:\n");
  printf("\t1. Translate a single ASCII character to Braille\n");
  printf("\t2. Translate a text file to Braille\n");
  printf("Enter your option: ");
  int option = 0;
  scanf("%d", &option);

  if (option == 1)
  {
    char input[2];
    printf("Enter a letter or a digit: ");
    scanf("%s", input);
    fputc_braille(input[0], stdout, map);
  }
  else if (option == 2)
  {
    printf("Input file: ");
    FILE *infile = open_file_given_mode("r");
    printf("Output file: ");
    FILE *outfile = open_file_given_mode("w+"); // 'w+' mode opens a file for both writing and reading

    translate_ascii_to_braille(infile, outfile, map);
    display_textfile(outfile);

    fclose(infile);
    fclose(outfile);
  }
  release_map(map);

  return 0;
}