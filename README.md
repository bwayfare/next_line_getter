Next line getter

Данная функция читает файл и возвращает строку до переноса, при каждом следующем вызове функции возвращается следующая строка.
Возвращаемые значения:
- Если файл не пустой, то возврпащается строка до переноса.
- Если файл закончился возвращается 0.
- Если файл не корректный файл, не найден файл, указана директория в качестве файла вернет -1.

Для работы требуется добавить в header файл мледующую строку
#define BUFFER_SIZE=n
За место n указать количество считываемых байт за один read файла.
