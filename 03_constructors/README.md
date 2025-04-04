# Конструктори и деструктори

Конструкторът е метод на класа, който се отличава по това, че има същото име като класа и няма тип на връщания резултат.
Има 3 вида конструктори:
1. Конструктор по подразбиране (default constructor) - не приема входни аргументи, нарича се още конструктор с нулев аргумент (на англ. _Zero-argument constructor_). Създава се автоматично от компилатора (с празно тяло), дори и програмистът да не е дефинирал такъв. 
2. Конструктор с параметри (parameterized constructor) - дава възможност за предаване на аргументи при създаване на обекта. Обикновено, подадените входни аргументи се използват за установяване на стойности на атрибутите на класа. Може да се използва и инициализиращ списък. 
3. Копиращ конструктор (copy constructor) - инициализира обект, използвайки друг обект от същия клас. Както и при конструктора по подразбиране, компилаторът неявно създава копи конструктор, ако това не е изрично направено от програмиста. 
4. Преместващ конструктор (move constructor) - 

В даден клас може да няма нито един конструктор, а може и да има няколко, като те се различават по вид и формални параметри.
Обикновено, конструкторите се декларират в `public` секцията.

Пример:
```c++
class Person {
public:
    Person() {}  // (1) конструктор по подразбиране
    Person(string name) : name(name) {}  // (2) Конструктор с 1 параметър
    Person(string name, int age) : name(name), age(age) {}  // (2-a) Конструктор с 2 параметъра
    Person(Person& obj) : name(obj.name), age(obj.age) {}  // (3) Копиращ конструктор
    ~Person() {}  // деструктор
private:
    string name;
    int age;
};
```
Използване на инициализиращ списък (на англ. _initializing list_):
```c++
Point(int i = 0, int j = 0): x(i), y(j) {}  // на x се присвоява стойността на i, а на y -> j
```
Предефиниране на конструктори
```c++
Person(string name) : name(name) {}  // Конструктор с 1 параметър
Person(string name, int age) : name(name), age(age) {}  // Предефиниране на инициализиращия конструктор
```

---
## Задачи

### Задача 1: Конструктор по подразбиране към класа за Банка
Допълнете класа за Банка от задача 4 ([02_04.cpp](../02_classes_and_objects/solutions/02_04.cpp)), като направите следните промени:
* всички атрибути на класа преместите в `private` секция;
* добавите конструктор по подразбиране, който първоначално инициализира атрибутите с нулеви стойности;
* добавете по един `set....()` метод за всеки атрибут, напр. `setAccountNumber()`;
* направете `const` методите, които не променят атрибутите на класа;
* променете `main()` програмата, така че да работи с новите изисквания;

### Задача 2: Инициализиращ конструктор към класа за Банка
Допълнете задача 1 като добавите инициализиращ конструктор, който има два входни аргумента - номера на акаунта и баланса.


### Задача 3: Система за управление на студенти
Да се създаде клас, който моделира информация за студенти в университет. Класът трябва да включва **_конструктор по подразбиране_** и **_конструктор с параметри_**.

Създайте клас `Student`, който има следните атрибути:
* `name` (тип `string`) – име на студента.
* `facultyNumber` (тип `string`) – факултетен номер.
* `averageGrade` (тип `double`) – среден успех.
* `year` (тип `int`) – година на обучение.

Добавете следните конструктори:
* Конструктор по подразбиране, който инициализира атрибутите на класа в тялото на конструктора:
  * `name` със стойност "`Unknown`".
  * `facultyNumber` със стойност "`000000`".
  * `averageGrade` със стойност `0.0`.
  * `year` със стойност `1`.
* Конструктор с параметри, който приема стойности за всички атрибути и ги инициализира в тялото на конструктора.

Напишете метод `printInfo()`, който отпечатва информация за студента във формат:
```c++
Name: [име]
F_number: [факултетен номер]
AVG grades: [среден успех]
Year: [година]
```
Нека методът да е константен.

Във функция `main()`:
* Създайте студент чрез конструктора по подразбиране и изведете информацията му.
* Създайте студент чрез конструктора с параметри със стойности по ваш избор и изведете информацията му.

### Задача 4: Модификация на задача 3
Преработете конструкторите от задача 3, така че да остане **един** **_конструктор със стойности по подразбиране_**. Когато създавате обект без аргументи, конструкторът ще използва стойностите по подразбиране, а ако създавате обект, на който подавате стойности, то те ще бъдат използвани.

Нека `main()` функцията изглежда така:
```c++
// Главна функция
int main() {
    // Създаване на студент чрез конструктора със стойности по подразбиране
    Student defaultStudent;
    cout << "Default student:" << endl;
    defaultStudent.printInfo();
    cout << endl;

    // Създаване на студент чрез конструктора с параметри
    Student paramStudent("Maria Ivanova", "123456", 5.75, 3);
    cout << "Student with parameters:" << endl;
    paramStudent.printInfo();

    return 0;
}
```

### Задача 5: Клас за град
Създайте клас `Town`, в който се съхраняват основни данни за градове.
Класът трябва да съдържа:
* Атрибути:
  *  `name` (тип: `string`) - име на града;
  - `population` (тип: `int`) - население на града;
  - `area` (тип: `double`) - площ на града в квадратни километри;
  - `mayor` (тип: `string`) - име на кмета;
  - `schools` (тип: `int`) - брой училища;
  - `hospitals` (тип: `int`) - брой болници.
* Конструктори:
  -  Конструктор по подразбиране, който инициализира атрибутите с "празни" стойности.
  -  Конструктор с параметри за инициализация на всички атрибути. **БОНУС**: нека конструкторът използва _инициализиращ списък_.
  - Копиращ конструктор, на който да подадете един входен параметър - обект от същия клас.
* Методи:
  - `setName()` - метод за задаване на име на града.
  - `getName()` - метод за връщане на името на града.
  - `calculatePopulationDensity()` - метод за изчисляване на гъстотата на населението (население / площ).
  - `addSchool()` - метод за увеличаване на броя на училищата с 1.
  - `printInfo()` - метод за отпечатване на информация за града (име, население, площ, кмет, брой училища, брой болници, гъстота на населението).
  - Нека всички методи, които не променят стойностите на атрибутите да бъдат константни.

В основната функция (`main()`) направете следното:
- Създайте обект на класа `Town` с подразбиращи се стойности.
- Създайте обект на класа `Town` с предварително зададени стойности (по ваш избор).
- Създайте трети обект на класа `Town`, който копира стойностите на първия обект.
- Променете името на **първия** обект с помощта на метода `setName()`.
- Добавете едно училище към **първия** обект с метода `addSchool()`.
- Отпечатайте информация за **трите** обекта с метода `printInfo()`.

**N.B.** решението в solutions е за стара версия на задачата!

### Задача 6: Конструктори към класа за правоъгълник (задача 2 от [02-classes_and_objects](../02_classes_and_objects))
Към класа за правоъгълник добавете конструктори:
- по подразбиране;
- с инициализиращи параметри;
- копиращ конструктор.

Използвайте вече съществуващия клас, който има атрибути и методи. 
Към него добавете още един метод, `printInfo()`, който да отпечатва атрибутите `width` и `height`.
Променете областта на видимост на атрибутите `width` и `height` - нека да станат `private`.

В `main()` програмата създайте 4 нови обекта, които да показват възможностите на трите конструктора. След създаването на всеки обект, извикайте и метода за отпечатване на информацията.
При създаването на обектите, чрез конструктора с параметри - предайте действителните параметри на конструктора по двата начина - за единия обект, чрез неявно извикване на конструктора, а за другия обект, чрез явно извикване на конструктора (вж. лекция - `3 Constructors and Destructors.pdf`).

**N.B.** решението в solutions е за стара версия на задачата!

### Задача 7: Управление на автомобилни данни
Създайте клас `Car`, който моделира автомобил. Класът трябва да съдържа:
* `private` атрибути за марка, модел и година на производство.
* Динамично заделена памет за регистрационния номер - използвайте тип `char`.
* Конструктор по подразбиране.
* Инициализиращ конструктор.
* Копиращ конструктор.
* Деструктор, който освобождава динамично заделената памет.
* Метод `printInfo()`, който извежда информация за автомобила.
* В `main()` програмата създайте няколко обекта от този клас (за всеки конструктор) и демонстрирайте работата му.
  
**N.B.** решението в solutions е частично!

### Задача 8:


### Задача 9: Управление на библиотека и списък с читатели (приятелски декларации)
Създайте клас `Book` със следните атрибути, конструктори и методи:
* `title` (заглавие) – низ.
* `author` (автор) – низ.
* `isBorrowed` (дали книгата е заета) – булева стойност.
* Конструктор за задаване на заглавие и автор.
* Метод `borrowBook()`, който отбелязва, че книгата е заета.
* Метод `returnBook()`, който отбелязва, че книгата е върната.
* Метод за извеждане на информация за книгата.

Създайте клас `Reader` със следните атрибути, конструктори и методи:
* `name` (име) – низ.
* `borrowedBook` (взета книга) – **указател** (!!!) към обект от тип Book.
* Конструктор за задаване на име.
* Метод `borrow(Book&)`, който позволява на читателя да вземе книга, ако тя не е заета.
* Метод `returnBook()`, който връща книгата.
* Метод за извеждане на информация за читателя и заетата книга.

Приятелски декларации:
* Класът `Reader` трябва да има достъп до член-данните на класа `Book`, за да проверява състоянието на книгата.
* Класът `Book` трябва да има достъп до член-данните на класа `Reader`, за да може да актуализира информация за това кой е взел книгата.

Оптимизация на кода:
* Опитайте се да оптимизирате кода си като модифицирате конструкторите, така че да входните аргументи да НЕ правят копия на подаваните променливи, а да използват референция към тях.
* Добавете `const` там, където е приложимо.

За тестване използвайте следния код:
```c++
// Създаваме обекти от класовете
Book book1("C++ Programming", "John Doe");
Reader reader1("Ivan Ivanov");

// Информация за книгата и читателя
book1.printInfo();
reader1.printInfo();

// Читателят взима книгата
reader1.borrow(book1);

// Отново извеждаме информация
book1.printInfo();
reader1.printInfo();

// Опит за взимане на вече заета книга
Reader reader2("Maria Petrova");
reader2.borrow(book1);

// Читателят връща книгата
reader1.returnBook();

// Състояние след връщане
book1.printInfo();
reader1.printInfo();

// Друг читател взима книгата
reader2.borrow(book1);

// Финално състояние
book1.printInfo();
reader2.printInfo();
```
Ако програмата ви работи правилно, ще получите следния резултат:
```c++
Title: C++ Programming, Author: John Doe, Status: Available
Reader: Ivan Ivanov, Book: None
Ivan Ivanov borrowed the book 'C++ Programming'.
Title: C++ Programming, Author: John Doe, Status: Borrowed
Reader: Ivan Ivanov, Book: C++ Programming
The book 'C++ Programming' is already borrowed.
Ivan Ivanov returned the book 'C++ Programming'.
Title: C++ Programming, Author: John Doe, Status: Available
Reader: Ivan Ivanov, Book: None
Maria Petrova borrowed the book 'C++ Programming'.
Title: C++ Programming, Author: John Doe, Status: Borrowed
Reader: Maria Petrova, Book: C++ Programming
```

---
## Допълнителни ресурси
1. Конструктори - https://www.geeksforgeeks.org/constructors-c/; https://www.w3schools.com/cpp/cpp_constructors.asp
2. Move construcotrs - https://www.geeksforgeeks.org/move-constructors-in-c-with-examples/
3. Инициализиращ списък - https://www.geeksforgeeks.org/when-do-we-use-initializer-list-in-c/
4. Предефиниране на конструктори - 
   * C++ - https://www.geeksforgeeks.org/constructor-overloading-c/; https://www.programiz.com/cpp-programming/constructor-overloading; https://www.tutorialspoint.com/cplusplus/cpp_constructor_overloading.htm
   * Java - https://www.geeksforgeeks.org/constructor-overloading-java/
   * python - https://www.geeksforgeeks.org/constructor-overloading-java/; https://stackoverflow.com/questions/58858556/how-can-i-perform-constructor-overloading-in-python
5. Референции, указатели и конструктори - https://stackoverflow.com/questions/9507008/passing-by-reference-to-a-constructor
6. 
 
