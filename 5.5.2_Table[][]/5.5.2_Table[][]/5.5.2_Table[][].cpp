#include <iostream>
#include <string>
#include <cassert>
#include <initializer_list>

template <typename T>
class Table
{
public:
	class Row;
	Table(std::initializer_list<std::initializer_list<T>> list)//конструктор для инициализации константной таблицы
	{
		if (list.size() > 0)
		{
			_rows = list.size();
			_table = new Row[list.size()];
			int i = 0;
			for (auto el : list)
			{
				_table[i++] = Row{ el };//присваивание перемещением
			}
		}
		else
		{
			_rows = 0;
			_table = nullptr;
		}		
	}
	Table(const int &rows,const int &columns)
	{
		if (rows > 0 && columns > 0)
		{
			_rows = rows;
			_table = new Row[rows];
			for (int i = 0; i < _rows; i++)
			{
				_table[i] = Row(columns);//присваивание перемещением
			}
		}
		else
		{
			_rows = 0;
			_table = nullptr;
		}		
	};
	Row &operator[](int index)
	{
		assert(index >= 0 && index < _rows && "Недопустимый индекс!");
		if (index >= 0 && index < _rows)
		{
			return _table[index];
		}		
	};
	const Row &operator[](int index) const//константный оператор для константной таблицы
	{
		assert(index >= 0 && index < _rows && "Недопустимый индекс!");
		if (index >= 0 && index < _rows)
		{
			return _table[index];
		}
	};
	const std::string Size() const
	{
		if (_rows > 0)
		{
			return std::to_string(_rows) + "x" + std::to_string(_table->getColumns());
		}
		else
		{
			return "0x0";
		}		
	}
	~Table()
	{
		if (_table != nullptr)
		{
			for (int i = 0; i < _rows; i++)
			{
				delete[] _table[i].getRow();
				_table[i].setRow(nullptr);
			}
			delete[] _table;
			_table = nullptr;
		}
	};
	
private:
	Row *_table;
	int _rows;

	class Row
	{
	public:
		Row()
		{
			_columns = 0;
			_row = nullptr;			
		};
		Row(std::initializer_list<T> list)
		{
			if (list.size() > 0)
			{
				_columns = list.size();
				_row = new T[list.size()]();
				int i = 0;
				for (auto el : list)
				{
					_row[i++] = el;
				}
			}
			else
			{
				_columns = 0;
				_row = nullptr;
			}
		}
		Row(int columns)
		{
			if (columns > 0)
			{
				_columns = columns;
				_row = new T[columns]();
			}
			else
			{
				_columns = 0;
				_row = nullptr;
			}					
		};
		Row &operator=(Row &&other) noexcept//присваивание перемещением для конструктора Table
		{
			if (this != &other)
			{
				delete[] _row;
				_row = other._row;
				_columns = other._columns;
				other._row = nullptr;
				other._columns = 0;
			}
			return *this;
		}
		const T &operator[](int index) const//константный оператор для константной таблицы
		{
			assert(index >= 0 && index < _columns && "Недопустимый индекс!");
			if (index >= 0 && index < _columns)
			{
				return _row[index];
			}
		};
		T &operator[](int index)
		{
			assert(index >= 0 && index < _columns && "Недопустимый индекс!");
			if (index >= 0 && index < _columns)
			{
				return _row[index];
			}
		};
		int getColumns()
		{
			return _columns;
		};
		void setColumns(int columns)
		{
			_columns = columns;
		};
		T *getRow()
		{
			return _row;
		};
		void setRow(T* row)
		{
			_row = row;
		}
		~Row()
		{
			delete[] _row;
		}
	private:
		T *_row;
		int _columns;
	};
};


int main()
{
	setlocale(LC_ALL, "RU");

	//Таблица volatile
	Table<double> t1(5, 2);
	std::cout << "Size = " << t1.Size() << '\n';
	t1[4][1] = 15.1;
	std::cout << "t1[4][1] = " << t1[4][1] << "\n\n";

	//Таблица const
	const Table<int> t2{ {1,2,3}, {4,5,6} };
	std::cout << "Size = " << t2.Size() << '\n';
	//t2[1][2] = 15; //- присвоение невозможно для const Table
	std::cout << "t2[1][2] = " << t2[1][2];

}
