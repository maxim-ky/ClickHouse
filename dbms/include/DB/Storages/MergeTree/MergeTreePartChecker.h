#pragma once

#include <DB/Storages/MergeTree/MergeTreeData.h>


namespace DB
{

class MergeTreePartChecker
{
public:
	/** Полностью проверяет данные кусочка:
	  *  - Вычисляет контрольные суммы и сравнивает с checksums.txt.
	  *  - Для массивов и строк проверяет соответствие размеров и количества данных.
	  *  - Проверяет правильность засечек.
	  * Бросает исключение, если кусок испорчен или если проверить не получилось (TODO: можно попробовать разделить эти случаи).
	  * Если strict, требует, чтобы для всех столбцов из columns.txt были файлы, и чтобы засечки не указывали в конец сжатого блока.
	  */
	static void checkDataPart(String path, size_t index_granularity, bool strict, const DataTypeFactory & data_type_factory);
};

}
