
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

/* A typedef for a linked list of strings 

   No changes are needed here.

*/
struct __list_struct_t {
  char                   *str;
  struct __list_struct_t *next;
};
typedef struct __list_struct_t list_t;


/* Function to call in case malloc or calloc cannot allocate new
   memory because no memory is left.

   No changes are needed here.

   THIS FUNCTION NEEDS TO BE CALLED IN ALL PLACES WHERE MEMORY IS
   ALLOCATED AND THE ALLOCATION FUNCTION RETURNS NULL BECAUSE NO
   MEMORY IS LEFT.

*/
void error_no_memory_left() {
  fprintf(stderr, "No memory left.\n");
  exit(1);
}


/* Gets input from the user in the form of a string. The string
   contains up to n characters, including the end marker '\0'.

   No changes are needed here.

*/
void input_string(char str[], int n) {
  char c;
  int i;
  int first;
  
  if (n < 1) return;
  first = 1;
  for (i=0; i<n-1; i++) {
    scanf("%c", &c);
    if (c == '\n') {
      if (first) {
	first = 0;
	i = -1;
	continue;
      } else {
	break;
      }
    }
    str[i] = c;
    first = 0;
  } 
  str[i] = '\0';
}

/* A function to add a string to a linked list 
   
   The function copies the string after allocating enough memory for
   it.

*/
list_t *add_to_list(char *str, list_t *list) {
  list_t *new_list;
  
  new_list = (list_t *) malloc(sizeof(list_t));
  if (new_list == NULL) {
    error_no_memory_left();
  }
  new_list->str = (char *) calloc(strlen(str) + 1, sizeof(char));
  if (new_list->str == NULL) {
    error_no_memory_left();
  }
  strcpy(new_list->str, str);
  new_list->next = list;
  return new_list;
}


/* Deletes a list by freeing all its memory. Also frees the memory
   taken by the strings in the list.
*/
void delete_list(list_t *list) {
  list_t *curr;
  list_t *temp;
  curr = list;
  while (curr != NULL) {
    temp = curr;
    curr = curr->next;
    free(temp->str);
    free(temp);
  }
}


/* A function to print out a list, each string on one line */
void print_list(list_t *list) {
  list_t *curr;

  for (curr = list; curr != NULL; curr=curr->next){
    printf("%s\n", curr->str);
  }
}


/* A function to compute the length of a list */
int length_list(list_t *list) {
  list_t *curr;
  int n;

  n = 0;
  for (curr = list; curr != NULL; curr=curr->next) {
    n++;
  }
  return n;
}


/* A function to revert a list.

   The function recreates a new list. Each string gets copied in
   memory into a newly allocated string.

*/
list_t *revert_list(list_t *list) {
  list_t *new_list;
  list_t *curr;

  new_list = NULL;
  for (curr = list; curr != NULL; curr=curr->next) {
    new_list = add_to_list(curr->str, new_list);
  }
  return new_list;
}


/* A function to copy a list without reverting it.

   The function recreates a new list. Each string gets copied in
   memory into a newly allocated string.

   This function must not call revert_list. It must not free any
   memory. It needs to copy the list without twice reverting it.

*/
list_t *copy_list(list_t *list) {
  list_t *curr, *prev, *copied_list, *new_node;

  copied_list = NULL;
  prev = NULL;

  for (curr = list; curr != NULL; curr=curr->next) {
    new_node = (list_t *) malloc(sizeof(list_t));
    if (new_node == NULL) {
      error_no_memory_left();
    }
    new_node->str = (char *) calloc(strlen(curr->str) + 1, sizeof(char));
    if (new_node->str == NULL) {
      error_no_memory_left();
    }
    strcpy(new_node->str, curr->str);
    new_node->next = NULL;
    if (copied_list == NULL) {
      copied_list = new_node;
    } else {
      prev->next = new_node;
    }
    prev = new_node;
  }
  return copied_list;
}


/* Converts the list to an array of strings. The strings are copied
   into newly allocated character arrays. 

   "Returns" both the new array as well as its length. The mechanism
   to return two results from a C function is the usual one: through
   pointers.

   If the list is empty (i.e. if the list pointer is NULL), 
   sets *array to NULL and the length to 0.

*/
void convert_to_array(char ***array, int *n, list_t *list) {
  list_t *curr;
  int i;

  curr = NULL;

  if (list == NULL) {
    *array = NULL;
    *n = 0;
  }
  *n = length_list(list);
  
  *array = (char **) calloc(*n, sizeof(char*));
  if (*array == NULL) {
      error_no_memory_left();
  }
  i = 0;
  for (curr = list; curr != NULL; curr=curr->next) {
    (*array)[i] = (char *) calloc((strlen(curr->str)+1), sizeof(char));
    if (*array[i] == NULL){
      error_no_memory_left();
    }
    strcpy((*array)[i], curr->str);
    ++i;
  }
}


/* Converts an array of length n to a list. The strings are 
   copied into newly allocated memory locations.

   If the length is zero or negative returns NULL.

*/
list_t *convert_from_array(char **array, int n) {
  list_t *new_list;
  
  if (n <= 0) return NULL;
 
  new_list = NULL;
  for (int i = n - 1; i > -1; --i) {
    new_list = add_to_list(array[i], new_list);
  }
  return new_list;
}


/* Compares two lists.

   If the lists are equal, returns a non-zero value (like 1).
   
   If the lists differ, returns zero.

   Two lists differ if they have different length or if at a certain
   index, they contain strings which are not equal. Two lists that 
   do not differ are equal.

   This function may use the strcmp function. The strcmp function
   returns zero for two equal strings and returns a non-zero value
   otherwise.

   THIS FUNCTION MUST NOT ALLOCATE ANY MEMORY.

   THIS FUNCTION MUST RETURN ZERO AS SOON AS IT KNOWS THAT THE TWO
   LISTS CANNOT BE EQUAL.

*/
int compare_lists(list_t *a, list_t *b) {
  list_t *a_curr, *b_curr;

  for (a_curr = a, b_curr = b; a_curr != NULL, b_curr != NULL; (a_curr = a_curr->next), (b_curr = b_curr->next)) {
    if (strcmp(a_curr->str, b_curr->str) != 0) {
      return 0;
    }
  }
  if ((a_curr != NULL) || (b_curr != NULL)) {
    return 0;
  } else {
    return 1;
  }
  /*list_t *a_curr, *b_curr;
  int matching = 1, val_test;

  a_curr = a;
  b_curr = b;
  while (matching) {
    if (((a_curr == NULL) && (b_curr != NULL)) || ((a_curr != NULL) && (b_curr == NULL))) {
      matching = 0;
    }
    if ((b_curr == NULL) && (a_curr == NULL)) {
      return 1;
    }
    val_test = strcmp(a_curr->str, b_curr->str);
    if (val_test != 0) return 0;
    a_curr = a_curr->next;
    b_curr = b_curr->next;
  }
  return 0; */
}

/* Adds a string to an existing list. Adds the string *before* the
   k-th element of the existing list. The first element of the 
   existing list has index zero.

   MODIFIES THE LIST ***IN PLACE***, DOES ***NOT*** COPY THE LIST.

   Returns the MODIFIED list.

   If the list is empty at the beginning, returns a list with 
   one element, containing the given string.

   The string is copied into a newly allocated memory location.

   If k is negative, adds the element to the beginning of the list.
   
   If k is equal to or greater than the length of the list, adds the
   element to the end of the list.

*/
list_t *add_before_kth_index(char *str, list_t *list, int k) {
  list_t *new_list, *curr, *temp, *first_in_list;
  int count;

  first_in_list = list;
  new_list = (list_t *) malloc(sizeof(list_t));
  new_list->str = (char *) malloc(sizeof(*str));
  strcpy(new_list->str, str);

  if (list == NULL) {
    new_list->next = NULL;
    return new_list;
  } 
  if (k <= 0) {
    new_list->next = list;
    return new_list;
  }
  if (k >= length_list(list)){
    new_list->next = NULL;
    for (curr = list; curr != NULL; curr = curr->next) {
      temp = curr;
    }
    temp->next = new_list;
    return first_in_list;
  }

  count = 0;
  for (curr = list; count < k - 1; curr = curr->next){
    ++count;
  }
  temp = curr->next;
  new_list->next = temp;
  curr->next = new_list;

  return first_in_list;
}


/* The main function 

   No changes are needed here.

*/
int main(int argc, char **argv) {
  const int STRING_BUFFER_LENGTH = 4096;
  char str[STRING_BUFFER_LENGTH];
  list_t *temp_list;
  list_t *list;
  list_t *copied_list;
  char **array;
  int n;
  int i;
  list_t *recreated_list;
  list_t *comparison_list;
  int k;

  temp_list = NULL;
  while (1) {
    printf("Please enter a string. Enter \"quit\" (without the quotes) to end the input.\n");
    input_string(str, STRING_BUFFER_LENGTH);
    if (strcmp(str, "quit") == 0)
      break;
    temp_list = add_to_list(str, temp_list);
  }
  list = revert_list(temp_list);
  delete_list(temp_list);

  printf("You have entered %d strings. The strings you entered are:\n", length_list(list));
  print_list(list);
  copied_list = copy_list(list);
  
  array = NULL;
  n = 0;
  convert_to_array(&array, &n, list);
  if (array != NULL) {
    printf("Here are again the %d strings you entered:\n", n);
    for (i=0; i<n; i++) {
      printf("%s\n", array[i]);
    }
  }
  recreated_list = NULL;
  if (array != NULL) {
    recreated_list = convert_from_array(array, n);
  }
  if (compare_lists(list, recreated_list)) {
    printf("The list could be successfully recovered.\n");
  } else {
    printf("The list could NOT be successfully recovered.\n");
  }
  printf("Please enter yet another string.\n");
  input_string(str, STRING_BUFFER_LENGTH);
  printf("Please enter an integer: ");
  scanf("%d", &k);
  list = add_before_kth_index(str, list, k);

  printf("I added the string \"%s\" before the %d-th element of the list. The list is now:\n", str, k);
  print_list(list);

  printf("The copied list still is:\n");
  print_list(copied_list);
  
  comparison_list = add_to_list("Snowflake", add_to_list("Snowflake", add_to_list("Little snowflake", NULL)));
  if (compare_lists(copied_list, comparison_list)) {
    printf("The copied list is equal to \"Snowflake\", \"Snowflake\", \"Little snowflake\".\n");
  } else {
    printf("The copied list is NOT equal to \"Snowflake\", \"Snowflake\", \"Little snowflake\".\n");
  }
    
  delete_list(list);
  delete_list(copied_list);
  if (array != NULL) {
    for (i=0; i<n; i++) {
      free(array[i]);
    }
    free(array);
  }
  delete_list(recreated_list);
  delete_list(comparison_list);
  
  return 0;
}

