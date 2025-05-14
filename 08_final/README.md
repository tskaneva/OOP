# 12 седмица

Създайте програма на C++, която моделира умни устройства в интелигентен дом, използвайки обектно-ориентирани принципи. Системата трябва да включва:
1. Абстрактен базов клас `SmartDevice`:
   * Чисто виртуална функция `showStatus() const`
   * Чисто виртуална функция `reset()`
   * Деструктор `virtual ~SmartDevice()`
5. Клас `NetworkEnabled` (наследява `SmartDevice`):
   * Поле `string ipAddress`
   * Метод `ping() const` – извежда IP адреса на устройството
3. Клас `EnergyConsuming` (наследява `SmartDevice`):
   * Поле `double powerWatts`
   * Метод `reportEnergy() const` – извежда текущата консумация на енергия
4. Клас `SmartPlug` (наследява `NetworkEnabled` и `EnergyConsuming`):
   * Булево поле `isOn`
   * Метод `toggle()` – сменя състоянието (вкл./изкл.)
   * Имплементира `showStatus()` и `reset()` 
5. Клас `SmartCamera` (наследява само `NetworkEnabled`):
   * Булево поле `recording`
   * Метод `startRecording()` – стартира запис
   * Имплементира `showStatus()` и `reset()`
6. Клас `ElectricHeater` (наследява само `EnergyConsuming`):
   * Целочислено поле `temperature`
   * Метод `setTemperature(int)` – задава температура
   * Имплементира `showStatus()` и `reset()`
     
В `main()` функцията:
1. Създайте масив от указатели към `SmartDevice`.
3. Всеки елемент трябва да сочи към различен обект (`SmartPlug`, `SmartCamera`, `ElectricHeater`, ...).
5. Извикайте `showStatus()` за всички устройства.
7. Извикайте уникалните методи на всяко устройство (`toggle()`, `startRecording()`, `setTemperature()`, ...).
9. Извикайте `reset()` и след това отново `showStatus()`.
11. Освободете динамично заделената памет с `delete`.
12. Използвайте `const` където е приложимо
13. Използвайте `override` за виртуални методи
