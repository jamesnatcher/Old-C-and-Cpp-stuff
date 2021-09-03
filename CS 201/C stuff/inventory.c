
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/* A structure type for an item in the inventory of a store 

   The description is a string allocated with calloc.

*/
typedef struct __item_struct_t {
  int    id;
  char   *description;
  double price;
  int    quantity_available;
} item_t;

/* A structure type for an item in the order of a customer

 
*/
typedef struct __ordered_item_struct_t {
  item_t *item;
  int    quantity_ordered;
} ordered_item_t;

/* Function to call in case malloc or calloc cannot 
   allocate new memory because no memory is left.

   No changes are needed here.

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

/* A function that creates an item by allocating memory for the item
   and by filling the different fields of the item_t structure.

   The function returns a pointer to the newly created structure.

   The function uses malloc for the structure and uses calloc for the
   description string field of the structure.

   The function copies the id, description, price and quantity
   arguments into the newly created structure.

   The function checks the return value of the malloc and calloc 
   allocation calls. If NULL is returned, the function calls 
   the error_no_memory_left() function to signal failure.

   The function may use the strcpy and strlen library functions.

   If the quantity given in argument is negative, the function forces
   the quantity_available field of the newly created item to
   0. Similarly, the price is forced to be non-negative.

*/
item_t *create_item(int id, char description[], double price, int
		    quantity_available) {
  item_t* user_item;

  user_item = (item_t*)malloc(sizeof(item_t));
  if (user_item == NULL) {
    error_no_memory_left();
  }
  user_item->description = (char*)calloc(strlen(description) + 1, sizeof(char));
  if (user_item->description == NULL) {
    error_no_memory_left();
  }

  strcpy(user_item->description, description);
  user_item->id = id;
  if (price < 0) {
    user_item->price = 0;
  } else{
  user_item->price = price;
  }
  if (quantity_available < 0) {
    user_item->quantity_available = 0;
  } else{
    user_item->quantity_available = quantity_available;
  }

  return user_item;
}

/* A function to delete an item. 

   It calls free() to deallocate the memory for the description field.
   
   It calls free() to deallocate the memory for the item.
*/
void delete_item(item_t *item) {
  free(item);
  free(item->description);
}

/* A function to compare two items by ID.

   Returns 0 if the IDs of the two items a and b differ.

   Returns a non-zero value (like 1) otherwise.

*/
int compare_items(item_t *a, item_t *b) {
  if (a->id == b->id) {
    return 1;
  }
  return 0;
}

/* A function to print out an item */
void print_item(item_t *item) {
  printf("Item ID:          %d\n", item->id);
  printf("Item description: %s\n", item->description);
  printf("Item price:       %0.2lf\n", item->price);
  printf("Item quantity:    %d\n", item->quantity_available);
}

/* A function that prompts the user for a new item ID, description,
   price and quantity and then calls create_item to create the item.

   No change is needed here.

*/
item_t *input_and_create_item() {
  const int description_len = 128;
  int id;
  char description[description_len];
  double price;
  int quantity_available;

  printf("Please enter a new item ID: ");
  scanf("%d", &id);

  printf("Please enter an item description: ");
  input_string(description, description_len);

  printf("Please enter an item unit price: ");
  scanf("%lf", &price);
  while (price <= 0.00) {
    printf("The unit price cannot be negative nor zero.\n");
    printf("Please enter an item unit price: ");
    scanf("%lf", &price);
  }

  printf("Please enter the quantity of items in stock: ");
  scanf("%d", &quantity_available);
  while (quantity_available < 0) {
    printf("The quantity of items in stock cannot be negative.\n");
    printf("Please enter the quantity of items in stock: ");
    scanf("%d", &quantity_available);
  }

  return create_item(id, description, price, quantity_available);
}

/* A function to add the item item to the inventory 
   given by an array old_inventory of length old_inventory_length.

   The function checks if an item with the same ID already exists.  

   If this is the case, the function sets the array pointed to by
   new_inventory to the old_inventory array, sets the number of the
   elements of that array, pointed to by new_inventory_length, to the 
   old_inventory_length and returns 0.

   Otherwise, the function sets the number of the new elements in the
   inventory to the old inventory length plus one, allocates an array
   of the appropriate size for the new array, copies the existing
   elements from the old array to the new array, sets the array
   pointed to by new_inventory to this newly allocated array and
   returns a non-zero value (like 1).

   If the old_inventory array pointer is NULL or the
   old_inventory_length is negative, the function considers the
   old_inventory_length to be zero.

   Nothing needs to be changed in this function. The function is fully
   provided. STUDENTS MUST STUDY AND UNDERSTAND THIS FUNCTION IN ORDER
   TO BE ABLE TO WRITE THE NEXT FUNCTION BELOW.

*/
int add_item_to_inventory(item_t *(*new_inventory[]), int *new_inventory_length,
			  item_t *old_inventory[], int old_inventory_length,
			  item_t *item) {
  int i, exists;
  
  if ((old_inventory_length == 0) || (old_inventory == NULL)) {
    *new_inventory = (item_t **) malloc(sizeof(item_t *));
    if (*new_inventory == NULL) {
      error_no_memory_left();
    }
    *new_inventory_length = 1;
    (*new_inventory)[0] = item;
    return 1;
  }

  exists = 0;
  for (i=0; i<old_inventory_length; i++) {
    if (compare_items(old_inventory[i], item)) {
      exists = 1;
      break;
    }
  }
  if (exists) {
    *new_inventory = old_inventory;
    *new_inventory_length = old_inventory_length;
    return 0;
  }
  
  *new_inventory_length = old_inventory_length + 1;
  *new_inventory = (item_t **) calloc(*new_inventory_length, sizeof(item_t *));
  if (*new_inventory == NULL) {
    error_no_memory_left();
  }
  for (i=0; i<old_inventory_length; i++) {
    (*new_inventory)[i] = old_inventory[i];
  }
  (*new_inventory)[*new_inventory_length - 1] = item;
  free(old_inventory);
  return 1;
}

/* Deletes the item of index item_indes from the old_inventory array
   of size old_inventory_length, allocating a new array for the
   new_inventory array and setting the new_inventory_length to the new
   length.

   If no item of item_index exists, the function returns 0.

   Otherwise, the function performs its function and returns a
   non-negative value (like 1).

   In the case when the new inventory becomes empty because its
   last item gets deleted, the function sets the new inventory array
   to NULL. Caution: the pointer new_inventory is a pointer to the 
   array, not the array itself.

   This function does the inverse of the add_item_to_inventory
   function defined above. Get inspiration from the function above.
   
   The function deallocates the old_inventory array. It does not call
   delete_item function to deallocate the item deleted from the
   inventory though.

*/
int delete_item_from_inventory(item_t *(*new_inventory[]), int *new_inventory_length,
			       item_t *old_inventory[], int old_inventory_length,
			       int item_index) {
  int i, exists;

  if ((item_index >= old_inventory_length) && (item_index < 0)) return 0;

  if (old_inventory_length <= 1) {
    *new_inventory = NULL;
    return 1; 
  } else {
    *new_inventory_length = old_inventory_length - 1;
    *new_inventory = (item_t **) calloc(*new_inventory_length, sizeof(item_t *));
    if (*new_inventory == NULL) {
      error_no_memory_left();
    }
    for(i=0; i<old_inventory_length; ++i) {
      if (i != item_index) {
        (*new_inventory)[i] = old_inventory[i];
      }
    }
    free(old_inventory);
    return 1;
  }
}

/* A function to delete all items in the inventory array of length
   inventory_length.

   Calls delete_item on all items in the inventory.

   Calls free to deallocate the memory for the inventory array.

   If the inventory array pointer is NULL or the inventory_length is
   negative or zero, does nothing.

*/
void delete_all_items_in_inventory(item_t *inventory[],
				   int inventory_length) {
  if ((inventory == NULL) || (inventory_length <= 0)) return;

  for (int i=0; i < inventory_length; ++i) {
    delete_item(inventory[i]);
  }
  free(inventory);
}

/* Prints all the items in the inventory array of length
   inventory_length.

   Calls print_item on all items in the inventory.

   If the inventory array pointer is NULL or the inventory_length is
   negative or zero, prints "No items in inventory." followed by a
   newline.

*/
void print_inventory(item_t *inventory[],
		     int inventory_length) {
  if ((inventory == NULL) || (inventory_length <= 0)) {
    printf("No items in inventory\n");
  } else {
    for (int i = 0; i < inventory_length; ++i){
      print_item(inventory[i]);
      printf("\n");
    }
  }
}    
/* Computes and returns the capital in all the items in the inventory
   array of length inventory_length.

   If the inventory array pointer is NULL or the inventory_length is
   negative or zero, returns 0.0.

   Otherwise returns the sum of the unit prices of all items 
   multiplied by the quantity of each item in stock.

*/
double compute_capital_in_inventory(item_t *inventory[],
				    int inventory_length) {
  double sum; 
  if ((inventory != NULL) && (inventory_length > 0)) {
    for (int i = 0; i < inventory_length; ++i) {
      sum += inventory[i]->price * inventory[i]->quantity_available; 
    }
    return sum;
  }
  return 0.0; 
}

/* Trys to find an item by its ID, among all the items in the
   inventory array of length inventory_length.

   If the inventory array pointer is NULL or the inventory_length is
   negative or zero, returns -1.

   Otherwise, searches for the item with the id given in argument.

   If the item with this ID is found, returns the index of the item in
   the inventory array.

   Otherwise, returns -1.
  
*/
int find_item_by_id(item_t *inventory[], int inventory_length,
		    int id) {
  if ((inventory != NULL) && (inventory_length > 0)) {
    for (int i = 0; i < inventory_length; ++i) {
      if (inventory[i]->id == id) {
        return i;
      }
    }
  }
  return -1;
}

/* Trys to find an item by its description, among all the items in the
   inventory array of length inventory_length.

   If the inventory array pointer is NULL or the inventory_length is
   negative or zero, returns -1.

   Otherwise, searches for the item with the description given in argument.

   If the item with precisely this description is found, returns the
   index of the item in the inventory array.

   Otherwise, returns -1.
  
   This function may use the strcmp library function.

*/
int find_item_by_description(item_t *inventory[], int inventory_length,
			     char description[]) {
  if ((inventory != NULL) && (inventory_length > 0)) {
    for (int i = 0; i < inventory_length; ++i) {
      if (strcmp(inventory[i]->description, description) == 0) {
        return i;
      }
    }
  }
  return -1; 
}

/* Tries to save an inventory of length inventory_length to file with
   name filename

   Returns a non-zero value on success.

   Returns 0 on failure.

   Nothing needs to be changed in this function.

*/
int save_inventory_to_file(char filename[], item_t *inventory[], int inventory_length) {
  FILE *fd;
  size_t len, i;
  struct {
    int    id;
    size_t desc_len;
    double price;
    int    quantity_available;
  } temp;
  
  if (inventory == NULL) return 0;
  if (inventory_length <= 0) return 0;
  if (filename == NULL) return 0;
  len = (size_t) inventory_length;
  if (inventory_length != ((int) len)) return 0;
  
  fd = fopen(filename, "w");
  if (fd == NULL) return 0;
  
  if (fwrite(&len, sizeof(len), 1, fd) != ((size_t) 1))
    goto handle_write_error;
  
  for (i=((size_t) 0);i<=(len-((size_t) 1));i++) {
    temp.id = inventory[i]->id;
    temp.desc_len = strlen(inventory[i]->description);
    temp.price = inventory[i]->price;
    temp.quantity_available = inventory[i]->quantity_available;
    if (fwrite(&temp, sizeof(temp), 1, fd) != ((size_t) 1))
      goto handle_write_error;
    if (fwrite(inventory[i]->description, sizeof(char),
	       temp.desc_len, fd) != temp.desc_len)
      goto handle_write_error;
  }

  if (fclose(fd) != 0) return 0;
  return 1;

 handle_write_error:
  fclose(fd);
  return 0;
}

/* Tries to read an inventory of length inventory_length from a file with
   name filename

   Returns a non-zero value on success.

   Returns 0 on failure.

   Nothing needs to be changed in this function.

*/
int read_inventory_from_file(item_t *(*inventory[]), int *inventory_length, char filename[]) {
  FILE *fd;
  size_t len, i;
  struct {
    int    id;
    size_t desc_len;
    double price;
    int    quantity_available;
  } temp;
  item_t **new_inventory = NULL;
  int new_inventory_len;
  char *str;
  
  if (filename == NULL) return 0;

  fd = fopen(filename, "r");
  if (fd == NULL) return 0;

  if (fread(&len, sizeof(len), 1, fd) != ((size_t) 1))
    goto handle_read_error;

  new_inventory_len = (int) len;
  if (len != ((size_t) new_inventory_len)) {
    fclose(fd);
    return 0;  
  }
  new_inventory_len = 0;
  new_inventory = (item_t **) calloc(len, sizeof(item_t *));
  if (new_inventory == NULL) {
    error_no_memory_left();
  }

  for (i=((size_t) 0);i<=(len-((size_t) 1));i++) {
    if (fread(&temp, sizeof(temp), 1, fd) != ((size_t) 1))
      goto handle_read_error;
    str = (char *) calloc(temp.desc_len + 1, sizeof(char));
    if (str == NULL) {
      error_no_memory_left();
    }
    if (fread(str, sizeof(char), temp.desc_len, fd) != temp.desc_len) {
      free(str);
      goto handle_read_error;
    }
    new_inventory[i] = (item_t *) malloc(sizeof(item_t));
    if (new_inventory[i] == NULL) {
      error_no_memory_left();
    }
    new_inventory_len++;
    new_inventory[i]->id = temp.id;
    new_inventory[i]->description = str;
    new_inventory[i]->price = temp.price;
    new_inventory[i]->quantity_available = temp.quantity_available;
  }
  
  if (fclose(fd) != 0)
    goto handle_read_error;
  
  *inventory = new_inventory;
  *inventory_length = new_inventory_len;
  return 1;

 handle_read_error:
  if (new_inventory != NULL) {
    for (i=((size_t) 0);i<=(((size_t) new_inventory_len)-((size_t) 1));i++) {
      free(new_inventory[i]->description);
      free(new_inventory[i]);
    }
    free(new_inventory);
  }
  fclose(fd);
  return 0;  
}

/* Deletes an ordered item, without deleting the item 
   itself, which still continues to exist in the inventory
   even if the item gets deleted from an order.
*/
void delete_ordered_item(ordered_item_t *item) {
  free(item);
}

/* Prints an ordered item. Uses print_item to print the item,
   then prints the quantity that has been ordered for this item.
*/
void print_ordered_item(ordered_item_t *item) {
  print_item(item->item);
  printf("The amount ordered is: %d\n", item->quantity_ordered);
}

/* Computes and returns the price of the order.

   If the order pointer is NULL, returns 0.00
   If the order_length is less than or equal to zero, returns 0.00.

   Otherwise returns the sum of the unit prices multiplied by the
   quantities ordered.

*/
double compute_price_of_order(ordered_item_t *order[], int order_length) {
  double sum;
  if ((order == NULL) || (order_length <= 0)) return 0.00;
  for (int i=0; i<order_length; ++i) {
    sum += (order[i]->item->price) * (order[i]->quantity_ordered);
  }
  return sum;
}

/* Prints an order. 

   If the order pointer is NULL, or if the order length is
   non-positive, prints "No items ordered." on one line and "Total
   price of the order $0.00$" on the next line. Then starts a new
   line.

   Otherwise, prints all the items in the order, calling
   print_ordered_item, then prints "Total price of the order $"
   followed by the total price of the order, computed with
   compute_price_of_order, followed by a new line.

*/
void print_order(ordered_item_t *order[], int order_length) {
  if ((order == NULL) || (order_length <= 0)) {
    printf("No items ordered.\nTotal price of the order $0.00$\n");
    return;
  } else{
    for (int i = 0; i < order_length; ++i){
      print_ordered_item(order[i]);
    }
    printf("Total price of order: $%lf\n", compute_price_of_order(order, order_length));
  }
  
}

/* Executes an order by subtracting the ordered quantities from the
   quantities available in the inventory for each item.

   If the order pointer is NULL, or if the order length is
   non-positive, does nothing.

   Otherwise, subtracts the ordered quantity of each item 
   in the order from the available quantity for this item.
   
*/
void execute_order(ordered_item_t *order[], int order_length) {
  if ((order == NULL) || (order_length <= 0)) return;
  for (int i=0;i<order_length;++i){
    order[i]->item->quantity_available -= order[i]->quantity_ordered;
  }
}

/* Deletes all items in an order and deletes the array for the order.

   If the order pointer is NULL, or if the order length is
   non-positive, does nothing.

   Otherwise, calls delete_ordered_item on each item and frees the
   memory for the order array.

*/
void delete_all_items_in_order(ordered_item_t *order[], int order_length) {
  if ((order == NULL) || (order_length <= 0)) return;
  for (int i=0;i<order_length;++i){
    delete_ordered_item(order[i]);
  }

}

/* Trys to find an item in an order by its ID, among all the items in
   the order array of length order_length.

   If the order array pointer is NULL or the order_length is
   negative or zero, returns -1.

   Otherwise, searches for the item with the id given in argument.

   If the item with this ID is found, returns the index of the item in
   the order array.

   Otherwise, returns -1.
  
*/
int find_item_in_order_by_id(ordered_item_t *order[], int order_length,
			     int id) {
  if ((order != NULL) || (order_length <= 0)){
    for (int i=0;i<order_length;++i){
      if (order[i]->item->id == id){
        return i;
      }
    }
  }
  return -1; 
}

/* A function to add the item item with quantity quantity to the order
   given by an array old_order of length old_order_length.

   The function checks if an item with the same ID already exists.  

   If this is the case, the function sets the array pointed to by
   new_order to the old_order array, sets the number of the elements
   of that array, pointed to by new_order_length, to the
   old_order_length, increases the ordered quantity of the existing
   item in the order by the newly added quantity and returns.

   Otherwise, the function sets the number of the new elements in the
   order to the old order length plus one, allocates an array of the
   appropriate size for the new array, copies the existing elements
   from the old array to the new array, sets the array pointed to by
   new_order to this newly allocated array, adds the item item
   encapsulated in an ordered_item_t structure, which is duely
   allocated, to the array and returns.

   If the old_inventory array pointer is NULL or the
   old_inventory_length is negative, the function considers the
   old_inventory_length to be zero.

*/
void add_item_to_order(ordered_item_t *(*new_order[]), int *new_order_length,
		       ordered_item_t *old_order[], int old_order_length,
		       item_t *item, int quantity) {
  int i, exists, index_in_old_order;

  if ((old_order_length < 0) || (old_order == NULL)){
    old_order_length = 0;
    *new_order = (ordered_item_t**) malloc(sizeof(ordered_item_t*));
    if (new_order == NULL){
      error_no_memory_left();
    }
    (*new_order)[0] = (ordered_item_t*) malloc(sizeof(ordered_item_t));
    if ((new_order)[0] == NULL){
      error_no_memory_left();
    }
    *new_order_length = 1;
    (*new_order)[0]->item = item;
    (*new_order)[0]->quantity_ordered = quantity;
  }

  exists = 0;
  for (i=0; i<old_order_length; i++){
    if (compare_items(old_order[i]->item, item)) {
      exists = 1;
      index_in_old_order = i;
      break;
    }
  }
  if (exists) {
    old_order[i]->quantity_ordered += quantity;
    *new_order = old_order;
    *new_order_length = old_order_length;
  } else {
    *new_order_length = old_order_length + 1;
    *new_order = (ordered_item_t **) calloc(*new_order_length, sizeof(ordered_item_t*));
    if (new_order == NULL){
      error_no_memory_left();
    }
    for (i=0; i < old_order_length; ++i) {
      (*new_order)[i] = old_order[i];
    }
    (*new_order)[*new_order_length - 1] = (ordered_item_t*) malloc(sizeof(ordered_item_t ));
    if ((*new_order)[*new_order_length - 1] == NULL){
      error_no_memory_left();
    }
    (*new_order)[*new_order_length - 1]->item = item;
    (*new_order)[*new_order_length - 1]->quantity_ordered = quantity;
    free(old_order);
  }
}

/* Deletes the ordered item of index item_index from the old_order
   array of size old_order_length, allocating a new array for the
   new_order array and setting the new_order_length to the new length.

   If no item of item_index exists, the function returns 0.

   Otherwise, the function performs its function and returns a
   non-negative value (like 1).

   In the case when the new order becomes empty because its last item
   gets deleted, the function sets the new order array to
   NULL. Caution: the pointer new_order is a pointer to the array, not
   the array itself.

   This function does the inverse of the add_item_to_order function
   defined above.
   
   The function deallocates the old_order array. It does not call
   delete_ordered_item function to deallocate the item deleted from
   the order though.

*/
int delete_item_from_order(ordered_item_t *(*new_order[]), int *new_order_length,
			   ordered_item_t *old_order[], int old_order_length,
			   int item_index) {
  int i, exists;

  if ((item_index >= old_order_length) && (item_index < 0)) return 0;

  if (old_order_length <= 1) {
    *new_order = NULL;
    return 1;
  } else {
    *new_order_length = old_order_length - 1;
    *new_order = (ordered_item_t **) calloc(*new_order_length, sizeof(ordered_item_t*));
    if (new_order == NULL) {
      error_no_memory_left();
    }
    for (i=0; i<old_order_length; ++i) {
      if (i != item_index) {
        (*new_order)[i] = old_order[i];
      }
    }
    free(old_order);
    return 1;
  }
}

/* A function to display an order menu and to handle customer orders.

   Nothing needs to be changed here. Students are encouraged to study
   the program to understand how it works, though.

*/
void handle_customer_order(item_t *inventory[], int inventory_length) {
  int order_length = 0;
  ordered_item_t **order = NULL;
  char choice, dummy;
  const int description_len = 128;
  char description[description_len];
  int id, idx;
  ordered_item_t *deleted_item;
  ordered_item_t **new_order = NULL;
  int new_order_length;
  int quantity;

  do {
    printf("******** Customer Order Menu ********\n");
    printf("Please choose one of the following options:\n");
    printf("\n");
    printf(" p - Print the existing inventory\n");
    printf(" i - Find an item in the inventory by item ID\n");
    printf(" f - Find an item in the inventory by item description\n");
    printf(" o - Print the current order\n");
    printf(" a - Add an item to the current order\n");
    printf(" d - Delete an item from the current order\n");
    printf(" x - Execute the current order and return to the previous menu\n");
    printf(" q - Abandon the order, quit this menu and return to the previous menu\n");
  
    do {
      scanf("%c", &choice);
    } while (choice == '\n');
    scanf("%c", &dummy);
    
    switch (choice) {
    case 'p':
      printf("Items in the inventory:\n");
      print_inventory(inventory, inventory_length);
      break;
    case 'i':
      printf("Enter the ID of the item to be found: ");
      scanf("%d", &id);
      idx = find_item_by_id(inventory, inventory_length, id);
      if (idx < 0) {
	printf("No item with ID %d has been found.\n", id);
      } else {
	print_item(inventory[idx]);
      }
      break;
    case 'f':
      printf("Enter the description of the item to be found: ");
      input_string(description, description_len);
      idx = find_item_by_description(inventory, inventory_length, description);
      if (idx < 0) {
	printf("No item with description %s has been found.\n", description);
      } else {
	print_item(inventory[idx]);
      }
      break;
    case 'o':
      printf("Items in the current order:\n");
      print_order(order, order_length);
      break;
    case 'a':
      printf("Enter the ID of the item which you wish to add to the current order: ");
      scanf("%d", &id);
      idx = find_item_by_id(inventory, inventory_length, id);
      if (idx < 0) {
	printf("No item with ID %d exists.\n", id);
      } else {
	printf("The following item has been selected:\n");
	print_item(inventory[idx]);
	printf("Enter the quantity of the item for the current order: ");
	scanf("%d", &quantity);
	if (inventory[idx]->quantity_available < quantity) {
	  printf("The maximum quantity available for this item is %d. Lowering the ordered quantity from %d to %d.\n",
		inventory[idx]->quantity_available, quantity, inventory[idx]->quantity_available);
	  quantity = inventory[idx]->quantity_available;
	}
	add_item_to_order(&new_order, &new_order_length,
			  order, order_length,
			  inventory[idx], quantity);
	order = new_order;
	order_length = new_order_length;
      }      
      break;
    case 'd':
      printf("Enter the ID of the item which you wish to delete from the current order: ");
      scanf("%d", &id);
      idx = find_item_in_order_by_id(order, order_length, id);
      if (idx < 0) {
	printf("No item with ID %d exists in the current order.\n", id);
      } else {
	deleted_item = order[idx];
	if (delete_item_from_order(&new_order, &new_order_length,
				   order, order_length,
				   idx)) {
	  order = new_order;
	  order_length = new_order_length;
	  delete_ordered_item(deleted_item);
	} else {
	  printf("Could not delete the item from the current order.\n");
	}
      }            
      break;
    case 'x':
      execute_order(order, order_length);
      break;
    case 'q':
      break;
    }
    printf("\n");
  } while ((choice != 'q') && (choice != 'x'));

  delete_all_items_in_order(order, order_length);
  order = NULL;
  order_length = 0;
}

/* The main program. 

   Nothing needs to be changed here. Students are encouraged to study
   the program to understand how it works, though.

*/
int main(int argc, char **argv) {
  int inventory_length = 0;
  item_t **inventory = NULL;
  char choice, dummy;
  const int description_len = 128;
  char description[description_len];
  int id, idx, quantity;
  item_t *new_item;
  item_t **new_inventory;
  int new_inventory_length;
  item_t *deleted_item;
  const int filename_len = 8192;
  char filename[filename_len];

  do {
    printf("******** Inventory Management Program ********\n");
    printf("Please choose one of the following options:\n");
    printf("\n");
    printf(" o - Handle a customer order with existing inventory\n");
    printf(" p - Print the existing inventory\n");
    printf(" c - Print capital in inventory\n");
    printf(" i - Find an item by item ID\n");
    printf(" f - Find an item by item description\n");
    printf(" s - Change quantity in stock for an item\n");
    printf(" a - Add an item to the inventory\n");
    printf(" d - Delete an item from the inventory\n");
    printf(" w - Delete all items in the inventory\n");
    printf(" k - Write inventory to a file\n");
    printf(" r - Read inventory from a file\n");
    printf(" q - Quit this program\n");
    do {
      scanf("%c", &choice);
    } while (choice == '\n');
    scanf("%c", &dummy);
    
    switch (choice) {
    case 'o':
      handle_customer_order(inventory, inventory_length);
      break;
    case 'p':
      printf("Items in the inventory:\n");
      print_inventory(inventory, inventory_length);
      break;
    case 'c':
      printf("All the items in the inventory are worth $%.2lf\n",
	     compute_capital_in_inventory(inventory, inventory_length));
      break;
    case 'i':
      printf("Enter the ID of the item to be found: ");
      scanf("%d", &id);
      idx = find_item_by_id(inventory, inventory_length, id);
      if (idx < 0) {
	printf("No item with ID %d has been found.\n", id);
      } else {
	print_item(inventory[idx]);
      }
      break;
    case 'f':
      printf("Enter the description of the item to be found: ");
      input_string(description, description_len);
      idx = find_item_by_description(inventory, inventory_length, description);
      if (idx < 0) {
	printf("No item with description %s has been found.\n", description);
      } else {
	print_item(inventory[idx]);
      }
      break;
    case 's':
      printf("Enter the ID of the item for which you wish to change the quantity: ");
      scanf("%d", &id);
      idx = find_item_by_id(inventory, inventory_length, id);
      if (idx < 0) {
	printf("No item with ID %d exists.\n", id);
      } else {
	print_item(inventory[idx]);
	printf("Enter the new item quantity: ");
	scanf("%d", &quantity);
	while (quantity < 0) {
	  printf("The quantity of items in stock cannot be negative.\n");
	  printf("Enter the new item quantity: ");
	  scanf("%d", &quantity);
	}
	inventory[idx]->quantity_available = quantity;
      }      
      break;
    case 'a':
      new_item = input_and_create_item();
      if (add_item_to_inventory(&new_inventory, &new_inventory_length,
				inventory, inventory_length,
				new_item)) {
	inventory = new_inventory;
	inventory_length = new_inventory_length;
      } else {
	printf("Could not add the new item to the inventory.\n");
	delete_item(new_item);
      }
      break;
    case 'd':
      printf("Enter the ID of the item which you wish to delete from the inventory: ");
      scanf("%d", &id);
      idx = find_item_by_id(inventory, inventory_length, id);
      if (idx < 0) {
	printf("No item with ID %d exists.\n", id);
      } else {
	deleted_item = inventory[idx];
	if (delete_item_from_inventory(&new_inventory, &new_inventory_length,
				       inventory, inventory_length,
				       idx)) {
	  inventory = new_inventory;
	  inventory_length = new_inventory_length;
	  delete_item(deleted_item);
	} else {
	  printf("Could not delete the item from the inventory.\n");
	}
      }            
      break;
    case 'w':
      delete_all_items_in_inventory(inventory, inventory_length);
      inventory = NULL;
      inventory_length = 0;
      break;
    case 'k':
      printf("Enter the name of the file to store the inventory list in: ");
      input_string(filename, filename_len);
      if (save_inventory_to_file(filename, inventory, inventory_length)) {
	printf("Inventory successfully saved to file %s.\n", filename);
      } else {
	printf("Error saving the inventory to file %s.\n", filename);
      }
      break;
    case 'r':
      printf("Enter the name of the file to read the inventory list from: ");
      input_string(filename, filename_len);
      if (read_inventory_from_file(&new_inventory, &new_inventory_length, filename)) {
	printf("Inventory successfully read from file %s.\n", filename);
	delete_all_items_in_inventory(inventory, inventory_length);
	inventory = new_inventory;
	inventory_length = new_inventory_length;
      } else {
	printf("Error reading inventory from file %s.\n", filename);
      }
      break;
    case 'q':
      break;
    }
    printf("\n");
  } while (choice != 'q');

  delete_all_items_in_inventory(inventory, inventory_length);
  inventory = NULL;
  inventory_length = 0;

  return 0;
}
