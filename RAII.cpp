#define _CRT_SECURE_NO_WARNINGS


#include <cstdio>
#include <stdexcept>

class file {
public:
	file(const char* filename) : m_file_handle(std::fopen(filename, "w+")) {
		if (!m_file_handle)
			throw std::runtime_error("file open failure");
	}

	~file() {
		if (std::fclose(m_file_handle) != 0) {
			// fclose() может вернуть ошибку при записи на диск последних изменений
		}
	}

	void write(const char* str) {
		if (std::fputs(str, m_file_handle) == EOF)
			throw std::runtime_error("file write failure");
	}

private:
	std::FILE* m_file_handle;

	// Копирование и присваивание не реализовано.  Предотвратим их использование,
	// объявив соответствующие методы закрытыми.
	file(const file &);
	file & operator=(const file &);
};
 
// пример использования этого класса
void example_usage() {
	// открываем файл (захватываем ресурс)
	file logfile("logfile.txt");

	logfile.write("hello logfile!");

	// продолжаем использовать logfile...
	// Можно возбуждать исключения или выходить из функции не беспокоясь о закрытии файла; 
	// он будет закрыт автоматически когда переменная logfile выйдет из области видимости.
}