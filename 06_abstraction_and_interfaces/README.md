# Абстрактни класове и интерфейси.


### Задача 1:
Създайте йерархия от класове за представяне на различни видове служители в една компания. Използвайте абстрактен базов клас `Employee`, от който произлизат още три класа:
1. `Developer` – наследява `Employee`
2. `TeamLead` – наследява `Developer`
3. `Manager` – наследява `TeamLead`

Изисквания:

Абстрактен клас `Employee`:
* Два атрибута:` string name`, `int id`
* Абстрактен метод `double calculateSalary()`
* Метод `printInfo()` – _имплементиран_ метод, който отпечатва `name` и `id`
* Конструктор с параметри и конструктор по подразбиране

Клас `Developer`:
* Атрибути: `int linesOfCode`, `double ratePerLine`
* Метод `calculateSalary()` – изчислява заплатата като `linesOfCode * ratePerLine`
* Метод `debugCode()` - отпечатва съобщение
* Двата конструктора

Клас `TeamLead`:
* Допълнителни атрибути: `int teamSize`, `double bonusPerMember`
* Метод `calculateSalary()` – добавя бонус към заплатата от `Developer`
* Метод `conductMeeting()` - отпечатва съобщение за проведена среща
* Двата конструктора

Клас `Manager`:
* Допълнителни атрибути: `double baseSalary`, `double projectBonus`
* Метод `calculateSalary()` – връща `baseSalary + projectBonus`
* Метод `evaluatePerformance()`
* Двата конструктора

Във `main()`:
* Създайте обекти от всички класове с различни конструктори.
* Извикайте метода `printInfo()` и `calculateSalary()` за всеки обект.
* Извикайте по един специфичен метод (`debugCode()`, `conductMeeting()`, `evaluatePerformance()`).
* Използвайте поне един указател от тип `Employee*`, насочен към обект от производен клас.

