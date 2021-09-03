
#include <iostream>
#include <string>
#include <vector>

using namespace std;

/* A class to talk about items in stock */
class item {
private:
  int id;
  string description;
  double price;
  int quantity_available;

public:
  item(int id, string description, double price, int quantity_available);
  item(const item &other);

  int get_id();
  string get_description();
  double get_price();
  int get_quantity();

  void set_quantity(int quantity);

  bool operator==(item other);
  
  void print();

  static item input_item();
};

/* A constructor for an item 

   The constructor enforces a non-negative price and a non-negative
   quantity, by setting the member field to zero if that is not the
   case.

*/
item::item(int id, string description, double price, int quantity_available) {
  if (id < 0){
    this->id = 0;
  } else {
    this->id = id;
  }
  if (price < 0){
    this->price = 0;
  } else {
    this->price = price;
  }
  if (quantity_available < 0){
    this->quantity_available = 0;
  } else {
    this->quantity_available = quantity_available;
  }
  this->description = description;
}

/* A copy-constructor

   Nothing to be done here.

*/
item::item(const item &other) {
  this->id = other.id;
  this->description = other.description;
  this->price = other.price;
  this->quantity_available = other.quantity_available;
}

/* Returns the id of an item */
int item::get_id() {
  return this->id;
}

/* Returns the description of an item */
string item::get_description() {
  return this->description;
}

/* Returns the price of an item */
double item::get_price() {
  return this->price;
}

/* Returns the quantity in stock for an item */
int item::get_quantity() {
  return this->quantity_available;
}

/* Sets the quantity of an item in stock.

   The method enforces a non-negative quantity, setting the field to
   zero if this is not the case.

*/
void item::set_quantity(int quantity) {
  this->quantity_available = quantity;
}

/* A comparison operator for items. 

   The comparison is based on the id of an item only.

   Returns true iff the ids of the two items match.

*/
bool item::operator==(item other) {
  if (this->id == other.id){
    return true;
  }
  return false;
}

/* Prints out an item, one member field per line */
void item::print() {
  cout << "Item ID:          " << this->id << endl;
  cout << "Item description: " << this->description << endl;
  cout << "Item price:       " << this->price << endl;
  cout << "Item quantity:    " << this->quantity_available << endl;
  cout << endl;
}

/* A static method to input an item. 

   Nothing to be done here.

*/
item item::input_item() {
  int id;
  string description;
  double price;
  int quantity_available;
  
  cout << "Please enter a new item ID: ";
  cin >> id;
  cin.ignore(1, '\n');
  
  cout << "Please enter an item description: " << endl;
  getline(cin, description);

  cout << "Please enter a unit price: ";
  cin >> price;
  while (price <= 0.00) {
    cout << "The unit price cannot be negative nor zero." << endl;
    cout << "Please enter a unit price: ";
    cin >> price;
  }

  cout << "Please enter the number of items in stock: ";
  cin >> quantity_available;
  while (quantity_available < 0) {
    cout << "The quantity of items in stock cannot be negative." << endl;
    cout << "Please enter the number of items in stock: ";
    cin >> quantity_available;
  }

  return item(id, description, price, quantity_available);
}

/* A class to talk about an inventory of items */
class inventory {
private:
  vector<item> items;

public:
  inventory();
  inventory(const inventory &other);

  int get_number_of_items();
  item &get_item_at(int i);

  int get_item_index_by_id(int id);
  int get_item_index_by_description(string description);
  
  double get_capital();

  bool add_item(item item);
  void delete_item_at(int i);
  void delete_all_items();

  void print();
};

/* A default constructor for an empty inventory */
inventory::inventory() {

}

/* A copy-constructor

   Uncomment code once you added the missing member field in inventory
   class (above).

*/
inventory::inventory(const inventory &other) {
  items.clear();
  for (auto &i : other.items) {
    items.push_back(i);
  }
}

/* Returns the number of different items in stock */
int inventory::get_number_of_items() {
  return items.size();
}

/* Returns (a reference to) the item in stock at index i

   The indices go from 0 to n - 1, where n is the number
   of items in stock. 

   The method may fail if i is not a valid index.

*/
item &inventory::get_item_at(int i) {
  for (int n = 0; n < items.size(); ++n) {
    if (n == i) {
      return items.at(i);
    }
  }
}

/* Returns the index of the item with ID id. 

   If no such item is found, returns a negative value (like -1).

*/
int inventory::get_item_index_by_id(int id) {
  for (int i = 0; i < items.size(); i++){
    if (items.at(i).get_id() == id){
      return i;
    }
  }
  return -1; 
}

/* Returns the index of the item with the description description. 

   If no such item is found, returns a negative value (like -1).

*/
int inventory::get_item_index_by_description(string description) {

  for (int i = 0; i < items.size(); ++i) {
    if ((items.at(i).get_description()) == description) {
      return i;
    }
  }
  return -1;
}

/* Returns the capital in the inventory 

   The capital in the inventory is the sum of 
   the unit prices times the quantities in stock.

*/
double inventory::get_capital() {
  double sum;
  for (int i = 0; i < items.size(); ++i) {
    sum += (items.at(i).get_price() * items.at(i).get_quantity());
  }
  return sum;
}

/* Tries to add the item item to the inventory.

   Checks if the item item exists already in the inventory.  Uses the
   == operator on items to compare items.

   If the item exists already, returns false and does nothing else.

   Otherwise, adds the item to the inventory and returns true.

*/
bool inventory::add_item(item item) {
  for (int i = 0; i < items.size(); ++i) {
    if (items.at(i) == item) {
      return false;
    }
  }
  items.push_back(item);
  return true;
}

/* Deletes the item in the inventory at index i.

   The method does not need to work for invalid indices.

*/
void inventory::delete_item_at(int i) {
  items.erase(items.begin()+i);
}

/* Deletes all items in the inventory, making the inventory empty.

*/
void inventory::delete_all_items() {
  items.clear();
}
/* Prints all items in the inventory, one item after the other */
void inventory::print() {
  for (int i = 0; i < items.size(); ++i) {
    items.at(i).print();
  }
}

/* The main function 

   Nothing to be changed here.

*/
int main(int argc, char **argv) {
  char choice;
  inventory inventory;
  int id, idx;
  string description;
  int quantity;

  do {
    cout << "******** Inventory Management Program ********" << endl;
    cout << "Please choose one of the following options:" << endl;
    cout << endl;
    cout << " p - Print the existing inventory" << endl;
    cout << " c - Print capital in inventory" << endl;
    cout << " i - Find an item by item ID" << endl;
    cout << " f - Find an item by item description" << endl;
    cout << " s - Change quantity in stock for an item" << endl;
    cout << " a - Add an item to the inventory" << endl;
    cout << " d - Delete an item from the inventory" << endl;
    cout << " w - Delete all items in the inventory" << endl;
    cout << " q - Quit this program" << endl;
    cin >> choice;

    switch (choice) {
    case 'p':
      cout << "Items in the inventory: " << endl;
      inventory.print();
      break;
    case 'c':
      cout << "All items in the inventory are worth $" << inventory.get_capital() << endl;
      break;
    case 'i':
      cout << "Enter the ID of the item to be found: ";
      cin >> id;
      idx = inventory.get_item_index_by_id(id);
      if (idx >= 0) {
	inventory.get_item_at(idx).print();
      } else {
	cout << "No item with ID " << id << " has been found." << endl;
      }
      break;
    case 'f':
      cout << "Enter the description of the item to be found: ";
      cin.ignore(1, '\n');
      getline(cin, description);
      idx = inventory.get_item_index_by_description(description);
      if (idx >= 0) {
	inventory.get_item_at(idx).print();
      } else {
	cout << "No item with description " << description << " has been found." << endl;
      }      
      break;
    case 's':
      cout << "Enter the ID of the item for which you wish to change the quantity: ";
      cin >> id;
      idx = inventory.get_item_index_by_id(id);
      if (idx >= 0) {
	cout << "Please enter the new quantity: ";
	cin >> quantity;
	while (quantity < 0) {
	  cout << "Sorry. The quantity cannot be negative." << endl;
	  cout << "Please enter the new quantity: ";
	  cin >> quantity;
	}
	inventory.get_item_at(idx).set_quantity(quantity);
      } else {
	cout << "No item with ID " << id << " has been found." << endl;
      }      
      break;
    case 'a':
      if (inventory.add_item(item::input_item())) {
	cout << "The new item has been successfully added to the inventory." << endl;
      } else {
	cout << "The new item could not be added to the inventory." << endl;
      }
      break;
    case 'd':
      cout << "Enter the ID of the item which you wish to delete from the inventory: ";
      cin >> id;
      idx = inventory.get_item_index_by_id(id);
      if (idx >= 0) {
	inventory.delete_item_at(idx);
      } else {
	cout << "No item with ID " << id << " has been found." << endl;
      }            
      break;
    case 'w':
      inventory.delete_all_items();
      break;
    case 'q':
      break;      
    }
  } while (choice != 'q');

  return 0;
}
