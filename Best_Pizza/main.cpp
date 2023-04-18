#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;
map<int, string>::iterator it;
map<int, string> m;
vector<int> v;
int x;
class pizza {
private:
  int ingredients, cost, best;
  string name;

public:
  void SetName(string x) { name = x; }
  void SetIngredients(int ing) { ingredients = ing; }
  void SetCost(int c) { cost = c; }
  void BestPizza() {
    if (name == "youssef")
      best = (ingredients + cost) * 2;
    else
      best = ingredients + cost;
    m[best] = name;
    v.push_back(best);
  }
  void TheChoice() {
    for (int i = 0; i < v.size(); i++) {
      x = v[0];
      if (x > v[i])
        x = v[i];
    }
  }
  void Print() {
    cout <<endl<< "The cheapest pizza is:" << m[x] << endl;
    cout <<"The cost is : " << x << endl;
  }
};
int main() {
  int y;
  cout << "Num of pizza: ";
  cin >> y;
  pizza customer[y];
  for (int i = 0; i < y; i++) {
    int ing, cost;
    string name;
    cout << "Enter the name of the pizza" << endl;
    cin >> name;
    customer[i].SetName(name);
    cout << "Enter the number of the ingredients" << endl;
    cin >> ing;
    customer[i].SetIngredients(ing);
    cout << "Enter the cost" << endl;
    cin >> cost;
    customer[i].SetCost(cost);
    customer[i].BestPizza();
    customer[i].TheChoice();
  }
  for (int i = 0; i < 1; i++)
    customer[i].Print();
}