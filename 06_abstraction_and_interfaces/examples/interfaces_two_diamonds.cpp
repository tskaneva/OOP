#include <iostream>
#include <string>
using namespace std;

// Интерфейс
class IPrintable {
public:
    virtual void print() const = 0;
    virtual ~IPrintable() = default;
};

// Базов клас
class Document : public IPrintable {
protected:
    string title;
public:
    Document(const string& t) : title(t) {
        cout << "Document constructor: " << title << endl;
    }

    void print() const override {
        cout << "Printing base document: " << title << endl;
    }
};

// Два наследника
class Report : public virtual Document {
protected:
    string author;
public:
    Report(const string& t, const string& a)
        : Document(t), author(a) {
        cout << "Report constructor: author = " << author << endl;
    }

    void print() const override {
        cout << "Report by " << author << ", title: " << title << endl;
    }
};

class Invoice : public virtual Document {
protected:
    double amount;
public:
    Invoice(const string& t, double amt)
        : Document(t), amount(amt) {
        cout << "Invoice constructor: amount = " << amount << endl;
    }

    void print() const override {
        cout << "Invoice titled \"" << title << "\", amount: " << amount << endl;
    }
};

// Първи диамант
class CombinedDocument : public Report, public Invoice {
public:
    CombinedDocument(const string& t, const string& a, double amt)
        : Document(t), Report(t, a), Invoice(t, amt) {
        cout << "CombinedDocument constructor" << endl;
    }

    void print() const override {
        cout << "CombinedDocument: \"" << title << "\", by " << author << ", amount: " << amount << endl;
    }
};

// Второ ниво
class PrintableCombinedA : public virtual CombinedDocument {
public:
    PrintableCombinedA(const string& t, const string& a, double amt)
        : Document(t), CombinedDocument(t, a, amt) {
        cout << "PrintableCombinedA constructor" << endl;
    }

    void print() const override {
        cout << "PrintableCombinedA: \"" << title << "\", by " << author << ", amount: " << amount << endl;
    }
};

class PrintableCombinedB : public virtual CombinedDocument {
public:
    PrintableCombinedB(const string& t, const string& a, double amt)
        : Document(t), CombinedDocument(t, a, amt) {
        cout << "PrintableCombinedB constructor" << endl;
    }

    void print() const override {
        cout << "PrintableCombinedB: \"" << title << "\", by " << author << ", amount: " << amount << endl;
    }
};

// Втори диамант
class UltimateDocument : public PrintableCombinedA, public PrintableCombinedB {
public:
    UltimateDocument(const string& t, const string& a, double amt)
        : Document(t),
        CombinedDocument(t, a, amt),
        PrintableCombinedA(t, a, amt),
        PrintableCombinedB(t, a, amt) {
        cout << "UltimateDocument constructor" << endl;
    }

    void print() const override {
        cout << "UltimateDocument: \"" << title << "\", by " << author << ", amount: " << amount << endl;
    }
};

int main() {
    cout << "=== Constructing UltimateDocument ===" << endl;
    UltimateDocument doc("Project Summary", "Test", 1999.99);

    cout << "\n=== Calling print() ===" << endl;
    doc.print();

    cout << "\n=== Through interface pointer ===" << endl;
    IPrintable* printable = &doc;
    printable->print();

    return 0;
}
