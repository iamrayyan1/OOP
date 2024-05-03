#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Medicine {
protected:
    string name;
    string formula;
    int price;
    string manufactureDate;
    string expirationDate;

public:
    Medicine(string n, string f, int p, string m, string e)
        : name(n), formula(f), price(p), manufactureDate(m), expirationDate(e) {}

    void setName(string name) { this->name = name; }
    void setFormula(string formula) { this->formula = formula; }
    void setPrice(int price) { this->price = price; }
    void setManufactureDate(string m) { manufactureDate = m; }
    void setExpirationDate(string e) { expirationDate = e; }
    string getName() const { return name; }
    string getFormula() const { return formula; }
    int getPrice() const { return price; }
    string getManufactureDate() const { return manufactureDate; }
    string getExpirationDate() const { return expirationDate; }

    virtual void print() const {
        cout << "MEDICINE DETAILS:" << endl;
        cout << "Name: " << name << endl;
        cout << "Formula: " << formula << endl;
        cout << "Price: " << price << endl;
        cout << "Manufacturing Date: " << manufactureDate << endl;
        cout << "Expiration Date: " << expirationDate << endl;
    }

    bool operator==(const Medicine& obj) const {
        if (expirationDate == obj.expirationDate) {
            cout << "Expiry of both the medicines are same." << endl;
            return true;
        }
        else {
            cout << "Expiry of both the medicines are different." << endl << endl;
            return false;
        }
    }
};

class Tablet : public Medicine {
private:
    float sucroseLevel;

public:
    Tablet(string n, string f, int p, string m, string e, float sl)
        : Medicine(n, f, p, m, e), sucroseLevel(sl) {}

    void print() const override {
        Medicine::print();
        cout << "Sucrose Level(0-1): " << sucroseLevel << endl;
    }
};

class Capsule : public Medicine {
private:
    float absorptionPercentage;

public:
    Capsule(string n, string f, int p, string m, string e, float ap)
        : Medicine(n, f, p, m, e), absorptionPercentage(ap) {}

    void print() const override {
        Medicine::print();
        cout << "Absorption Percentage(1-100): " << absorptionPercentage << "%" << endl;
    }
};

class Syrup : public Medicine {
public:
    Syrup(string n, string f, int p, string m, string e)
        : Medicine(n, f, p, m, e) {}

    void print() const override {
        cout << "SYRUP DETAILS:" << endl;
        Medicine::print();
    }
};

class Pharmacist {
public:
    void searchMedicine(const vector<Medicine>& medicines, const string& formula) const {
        bool found = false;
        for (const Medicine& med : medicines) {
            if (med.getFormula() == formula) {
                cout << "MEDICINE FOUND: " << endl;
                med.print();
                found = true;
            }
        }
        if (!found) {
            cout << "No medicine found." << endl;
        }
    }
};

class Counter {
private:
    int revenue;

public:
    Counter() : revenue(0) {}

    void searchMedicine(const vector<Medicine>& medicines, const string& name) const {
        bool found = false;
        for (const Medicine& med : medicines) {
            if (med.getName() == name) {
                cout << "MEDICINE FOUND: " << endl;
                med.print();
                found = true;
            }
        }
        if (!found) {
            cout << "No medicine found." << endl;
        }
    }

    void updateRevenue(int amount) {
        revenue += amount;
    }

    int getRevenue() const {
        return revenue;
    }
};

int main() {
    Tablet t1("Paracetamol", "CO2", 50, "06-2021", "06-2024", 0.5);
    Capsule c1("Aspirin", "SSS", 20, "03-2021", "06-2023", 50);
    Syrup s1("Glucose", "O6", 30, "07-2021", "06-2025");

    vector<Medicine> medicines;
    medicines.push_back(t1);
    medicines.push_back(c1);
    medicines.push_back(s1);
    
    c1 == t1;

    Pharmacist p1;
    p1.searchMedicine(medicines, "SO2");
    cout << endl;
    p1.searchMedicine(medicines, "SSS");
    cout << endl;

    Counter c;
    c.searchMedicine(medicines, "Glucos");
    cout << endl;
    c.searchMedicine(medicines, "Glucose");
    cout << endl;
    c.updateRevenue(100);
    cout << "Revenue: " << c.getRevenue() << endl;

}

