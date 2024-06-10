#include <map>
#include <string>
#include <iostream>
using namespace std;

string add(string phone)
{
    string key; int bfr = 0; char val[8];
    bfr = stoi(phone.substr(0,2));
    sprintf (val, "%.i", bfr);
    if (bfr < 10) key += "0"; key += val;
    bfr = stoi(phone.substr(3,6));
    sprintf (val, "%.i", bfr);
    if (bfr < 10) key += "0"; key += val;
    bfr = stoi(phone.substr(6,8));
    sprintf (val, "%.i", bfr);
    if (bfr < 10) key += "0"; key += val;
    return key;
}

int main()
{
  int phone_num = 0;
  string operation, phone, sname;
  map<int, string> phonebook;
  multimap<string, int> phonebooks;
  map<int, string>::iterator it;
  typedef multimap<string, int>::iterator itf;
  while (operation != "q")
  {
    cout << "Insert operation: ";
    cin >> operation;
    if (operation == "add")
    {
      cout << "Insert phone number: ";
      cin >> phone;
      try
      { phone_num = stoi(add(phone)); }
      catch (const exception& e)
      { cerr << "Input error: " << "incorrect phone" << endl; continue; }
      it = phonebook.find(phone_num);
      if (it->first == phone_num)
      { cerr << "Phone is already reserved" << endl; continue; }
      cout << "Insert Surname: ";
      cin >> sname;
      phonebook.insert(pair<int, string> (phone_num, sname));
      phonebooks.insert(pair<string, int> (sname, phone_num));
    }
    else if (operation == "phone")
    {
      cout << "Insert phone number: ";
      cin >> phone;
      try
      { phone_num = stoi(add(phone)); }
      catch (const exception& e)
      { cerr << "Input error: incorrect phone" << endl; continue; }
      it = phonebook.find(phone_num);
      if (it->first == phone_num)
        cout << "#" << it->first << " " << it->second << endl;
      else cerr << "Not found" << endl;
    }
    else if (operation == "sname")
    {
      cout << "Insert Surname: ";
      cin >> sname;
      pair <itf, itf> pos;
      pos = phonebooks.equal_range(sname);
      if (pos.first->first != sname)
        cout << "Not found" << endl;
      for (; pos.first != pos.second; pos.first++)
        cout << "#" << pos.first->second << " " << pos.first->first << endl;
    }
    else if (operation != "q") cerr << "Input error: incorrect operation" << endl;
  }
}
