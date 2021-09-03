
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
  item() { }
  item(int id, string description, double price, int quantity_available);
  item(const item &other);
  virtual ~item() { }

  int get_id() const;
  string get_description() const;
  double get_price() const;
  int get_quantity() const;

  void set_id(int id);
  void set_description(string description);
  void set_price(double price);
  void set_quantity(int quantity);

  virtual string get_string() const;

  bool operator==(item other);

  friend ostream& operator<<(ostream& out, const item& item) {
    out << item.get_string();
    return out;
  }
};

/* A constructor for an item 
   
   The constructor uses the setters of this.

*/
item::item(int id, string description, double price, int quantity_available) {
  this->set_id(id);
  this->set_description(description);
  this->set_price(price);
  this->set_quantity(quantity_available);
}

/* A copy-constructor

   Nothing to be done here.

*/
item::item(const item &other) {
  this->set_id(other.get_id());
  this->set_description(other.get_description());
  this->set_price(other.get_price());
  this->set_quantity(other.get_quantity());
}

/* Returns the id of an item */
int item::get_id() const {
  return this->id; 
}

/* Returns the description of an item */
string item::get_description() const {
  return this->description;
}

/* Returns the price of an item */
double item::get_price() const {
  return this->price;
}

/* Returns the quantity in stock for an item */
int item::get_quantity() const {
  return this->quantity_available;
}

/* Sets the ID of an item */
void item::set_id(int id) {
  this->id = id;
}

/* Sets the description of an item */
void item::set_description(string description) {
  this->description = description;
}

/* Sets the price of an item 

   The method enforces a non-negative quantity, setting the field to
   zero if this is not the case.

*/
void item::set_price(double price) {
  if (price < 0){
    this->price = 0;
  } else{
    this->price = price; 
  }
}

/* Sets the quantity of an item in stock.

   The method enforces a non-negative quantity, setting the field to
   zero if this is not the case.

*/
void item::set_quantity(int quantity) {
  if (quantity < 0){
    this->quantity_available = 0;
  } else{
    this->quantity_available = price; 
  }
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

/* Returns a string containing all fields of 
   an item, converted to a string. 

   Returns for example

   "Television Set" (ID: 17) - 10 @ $2000.000000 ea.
   
   You can use to_string() to convert from int and double to strings.
   
*/

string item::get_string() const {
 
  return "\"" + this->get_description() + "\" (ID: " 
    + to_string(this->get_id()) + ") - " 
    + to_string(this->get_quantity()) + " @ $" 
    + to_string(this->get_price()) + " ea.";

}

/* A sub-class for perishable items */
class perishable_item : public item {
private:
  int best_before_year;
  int best_before_month;
  int best_before_day;
  
public:
  perishable_item() { }
  perishable_item(int id, string description, double price, int quantity_available,
		  int year, int month, int day);
  perishable_item(const perishable_item &other);
  virtual ~perishable_item() { }
  
  void set_best_before_year(int year);
  void set_best_before_month(int month);
  void set_best_before_day(int day);
  
  int get_best_before_year() const;
  int get_best_before_month() const;
  int get_best_before_day() const;

  virtual string get_string() const;
};

/* A constructor for a perishable item 
   
   The constructor uses the setters of this.

   Nothing to be done here.

*/
perishable_item::perishable_item(int id, string description, double price, int quantity_available,
				 int year, int month, int day) {
  this->set_id(id);
  this->set_description(description);
  this->set_price(price);
  this->set_quantity(quantity_available);
  this->set_best_before_year(year);
  this->set_best_before_month(month);
  this->set_best_before_day(day);
}

/* A copy-constructor

   Nothing to be done here.

*/
perishable_item::perishable_item(const perishable_item &other) {
  this->set_id(other.get_id());
  this->set_description(other.get_description());
  this->set_price(other.get_price());
  this->set_quantity(other.get_quantity());
  this->set_best_before_year(other.get_best_before_year());
  this->set_best_before_month(other.get_best_before_month());
  this->set_best_before_day(other.get_best_before_day());
}

/* A setter for the year */
void perishable_item::set_best_before_year(int year) {
  this->best_before_year = year;
}

/* A setter for the month 

   The setter enforces 1 <= month <= 12.

   If month < 1, sets the month to 1.
   If month > 12, sets the month to 12.

*/
void perishable_item::set_best_before_month(int month) {
  if (month < 1){
    this->best_before_month = 1;
  }
  else if (month > 12){
    this->best_before_month = 12;
  } else{
    this->best_before_month = month;
  }
}

/* A setter for the day

   The setter enforces 1 <= day <= 31.

   If day < 1, sets the day to 1.
   If day > 31, sets the day to 31.

*/
void perishable_item::set_best_before_day(int day) {
  if (day < 1){
    this->best_before_day = 1;
  }
  else if (day > 31){
    this->best_before_day = 31;
  } else{
    this->best_before_day = day;
  }
}

/* A getter for the year */
int perishable_item::get_best_before_year() const {
  return this->best_before_year;
}

/* A getter for the month */
int perishable_item::get_best_before_month() const {
  return this->best_before_month;
}

/* A getter for the day */
int perishable_item::get_best_before_day() const {
  return this->best_before_day;
}

/* An overridden version of get_string(), enhancing it with the date.

   Uses the parent's class get_string()

   Returns for example:

   "Milk" (ID: 42) - 100@ $2.990000 ea., Best before: 2020/12/12

*/
string perishable_item::get_string() const {

  return item::get_string() + ", Best before: " 
    + to_string(this->get_best_before_year()) + "/" 
    + to_string(this->get_best_before_month()) + "/" 
    + to_string(this->get_best_before_day());

}

/* A sub-class for perishable items that can provoke food allergies */
class allergy_item : public perishable_item {
private:
  vector <string> allergies;
  
public:
  allergy_item() { }
  allergy_item(int id, string description, double price, int quantity_available,
	       int year, int month, int day,
	       const vector<string> &allergies);
  allergy_item(const allergy_item &other);
  virtual ~allergy_item() { }
  
  void add_allergy(string allergy);
  const vector<string> &get_allergies() const;
  
  virtual string get_string() const;
};

/* A constructor for an allergy item 
   
   The constructor uses the setters of this.

   Nothing to be done here.

*/
allergy_item::allergy_item(int id, string description, double price, int quantity_available,
			   int year, int month, int day,
			   const vector<string> &allergies) {
  this->set_id(id);
  this->set_description(description);
  this->set_price(price);
  this->set_quantity(quantity_available);
  this->set_best_before_year(year);
  this->set_best_before_month(month);
  this->set_best_before_day(day);
  for (int i=0; i<allergies.size(); ++i) {
    this->add_allergy(allergies[i]);
  }
}

/* A copy-constructor

   Nothing to be done here.

*/
allergy_item::allergy_item(const allergy_item &other) {
  this->set_id(other.get_id());
  this->set_description(other.get_description());
  this->set_price(other.get_price());
  this->set_quantity(other.get_quantity());
  this->set_best_before_year(other.get_best_before_year());
  this->set_best_before_month(other.get_best_before_month());
  this->set_best_before_day(other.get_best_before_day());
  const vector <string> &temp = other.get_allergies();
  for (int i=0; i<temp.size(); ++i) {
    this->add_allergy(temp[i]);
  }
}

/* A mutator to add an allergy to an item 

   Nothing to be done here.

*/
void allergy_item::add_allergy(string allergy) {
  allergies.push_back(allergy);
}

/* A getter for the vector of food allergies 

   Nothing to be done here.

*/
const vector<string> &allergy_item::get_allergies() const {
  return allergies;
}

/* An overridden version of get_string(), enhancing it with the date.

   Uses the parent's class get_string()

   Returns for example:

   "Apple" (ID: 99) - 1664@ $0.990000 ea., Best before: 2021/12/12, Allergies: apples, hazelnuts

   Remark that commas need to be inserted between the allergy
   description but not after the last allergy

*/
string allergy_item::get_string() const {
  string allergy_list;
 
  for (int i = 0; i < allergies.size(); ++i){
    if (i < allergies.size() - 1){
      allergy_list += allergies.at(i) + ", ";
    } else {
      allergy_list += allergies.at(i);
    }
  }
  return perishable_item::get_string() + " Allergies: " + allergy_list;
  
  /* return "\"" + this->get_description() + "\" (ID: " + to_string(this->get_id()) + ") - " + to_string(this->get_quantity()) + "@ $" + to_string(this->get_price()) + " ea., Best before: " + to_string(this->get_best_before_year()) + "\\" + to_string(this->get_best_before_month()) + "\\" + to_string(this->get_best_before_day()) + ", Allergies: " + allergy_list; */

}

/* A function to input an item. 

   Nothing to be done here in terms of coding.

   READ THE FUNCTION'S CODE THOUGH

*/
item &input_item() {
  char choice;
  int id;
  string description;
  double price;
  int quantity_available;
  int year, month, day;
  vector<string> allergies;
  string line;

  cout << "Please choose the type of item:" << endl;
  cout << " g - generic item" << endl;
  cout << " p - perishable item" << endl;
  cout << " a - item which may provoke allergies" << endl;
  cin >> choice;
  
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

  switch (choice) {
  case 'p':
  case 'a':
    cout << "Please enter the month of the best-before-date: ";
    cin >> month;
    cout << "Please enter the day of the best-before-date: ";
    cin >> day;
    cout << "Please enter the year of the best-before-date: ";
    cin >> year;
    switch (choice) {
    case 'a':
      cout << "Please enter food allergies, one per line. Enter an empty line to stop the input" << endl;
      cin.ignore(1, '\n');
      while (1) {
	getline(cin, line);
	if (line == "")
	  break;
	allergies.push_back(line);
      }
      return *(new allergy_item(id, description, price, quantity_available,
				year, month, day,
				allergies));
    default:
      return *(new perishable_item(id, description, price, quantity_available,
				   year, month, day));
    }
    break;
  default:
    return *(new item(id, description, price, quantity_available));
  }
}

/* A class to talk about an inventory of items */
class inventory {
private:
  vector<item *> items;

public:
  inventory() { }
  inventory(const inventory &other);
  ~inventory();

  int get_number_of_items() const;
  item &get_item_at(int i);
  const vector<item *> &get_items() const;

  int get_item_index_by_id(int id) const;
  int get_item_index_by_description(string description) const;
  
  double get_capital() const;

  bool add_item(item &item);
  void delete_item_at(int i);
  void delete_all_items();

  friend ostream& operator<<(ostream& out, const inventory& inventory) {
    for (item *i : inventory.get_items()) {
      out << *i;
      out << endl;
    }
    return out;
  }

};

/* A copy-constructor

   Nothing to be done here.

*/
inventory::inventory(const inventory &other) {
  for (item *i : other.get_items()) {
    items.push_back(i);
  }
}

/* A destructor

   Nothing to be done here.

*/
inventory::~inventory() {
  this->delete_all_items();
}

/* Returns the number of different items in stock 

   Nothing to be done here.

*/
int inventory::get_number_of_items() const {
  return items.size();
}

/* Returns (a reference to) the item in stock at index i

   The indices go from 0 to n - 1, where n is the number
   of items in stock. 

   The method may fail if i is not a valid index.

   Nothing to be done here.

*/
item &inventory::get_item_at(int i) {
  return *items.at(i);
}

/* A getter for the vector of pointers to items 

   Nothing to be done here.

*/
const vector<item *> &inventory::get_items() const {
  return items;
}

/* Returns the index of the item with ID id. 

   If no such item is found, returns a negative value (like -1).

   Nothing to be done here. 

*/
int inventory::get_item_index_by_id(int id) const {
  for (int i=0; i<items.size(); ++i) {
    if (items[i]->get_id() == id) {
      return i;
    }
  }
  return -1;
}

/* Returns the index of the item with the description description. 

   If no such item is found, returns a negative value (like -1).

   Nothing to be done here.

*/
int inventory::get_item_index_by_description(string description) const {
  for (int i=0; i<items.size(); ++i) {
    if (items[i]->get_description() == description) {
      return i;
    }
  }
  return -1;
}

/* Returns the capital in the inventory 

   The capital in the inventory is the sum of 
   the unit prices times the quantities in stock.

   Nothing to be done here.

*/
double inventory::get_capital() const {
  double s = 0.00;
  for (int i=0; i<items.size(); ++i) {
    s += items[i]->get_price() * items[i]->get_quantity();
  }  
  return s;
}

/* Tries to add the item item to the inventory.

   Checks if the item item exists already in the inventory.  Uses the
   == operator on items to compare items.

   If the item exists already, returns false and does nothing else.

   Otherwise, adds the item to the inventory and returns true.

   Nothing to be done here.
   
*/
bool inventory::add_item(item &item) {
  for (int i=0; i<items.size(); ++i) {  
    if (*items[i] == item) {
      return false;
    }
  }
  items.push_back(&item);
  return true;
}

/* Deletes the item in the inventory at index i.

   The method does not need to work for invalid indices.

   Nothing to be done here.

*/
void inventory::delete_item_at(int i) {
  delete items[i];
  items.erase(items.begin() + i);
}

/* Deletes all items in the inventory, making the inventory empty.

   Nothing to be done here.

*/
void inventory::delete_all_items() {
  for (int i=0; i<items.size(); ++i) {
    delete items[i];
  }
  items.clear();
}

/* The main function 

   Nothing to be changed here.

   READ THE CODE THOUGH.

   Try it out for combinations of generic, perishable and allergy
   items. How does the print feature (marked with *****) know if it
   needs to print a best-before date or possibly a list of allergies?

   Put the answer here: <TODO> and discuss it with your TA. 

   TAs: Please take the correctness of the answer into account for the
   grade for this lab.


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
      cout << inventory << endl; /* ***** */
      break;
    case 'c':
      cout << "All items in the inventory are worth $" << inventory.get_capital() << endl;
      break;
    case 'i':
      cout << "Enter the ID of the item to be found: ";
      cin >> id;
      idx = inventory.get_item_index_by_id(id);
      if (idx >= 0) {
	cout << inventory.get_item_at(idx) << endl;
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
	cout << inventory.get_item_at(idx) << endl;
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
      if (inventory.add_item(input_item())) {
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
