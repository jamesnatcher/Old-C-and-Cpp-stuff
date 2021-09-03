
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
  if (a->id == a->id) {
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
    printf("Items in inventory:\n");
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

  do {
    printf("******** Inventory Management Program ********\n");
    printf("Please choose one of the following options:\n");
    printf("\n");
    printf(" p - Print the existing inventory\n");
    printf(" c - Print capital in inventory\n");
    printf(" i - Find an item by item ID\n");
    printf(" f - Find an item by item description\n");
    printf(" s - Change quantity in stock for an item\n");
    printf(" a - Add an item to the inventory\n");
    printf(" d - Delete an item from the inventory\n");
    printf(" w - Delete all items in the inventory\n");
    printf(" q - Quit this program\n");
    do {
      scanf("%c", &choice);
    } while (choice == '\n');
    scanf("%c", &dummy);
    
    switch (choice) {
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
