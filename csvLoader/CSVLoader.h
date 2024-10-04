#pragma once
#include <csvLoader/csvStructure/CSVData.h>

#include <utility>
#include <string>
#include <list>

class CSVLoader{
public:
    CSVLoader(const CSVLoader&) = delete;
    CSVLoader& operator=(const CSVLoader&) = delete;
    CSVLoader(CSVLoader&&) = delete;
    CSVLoader& operator=(const CSVLoader&&) = delete;

    /// <summary>
    /// インスタンスを取得
    /// </summary>
    /// <returns>インスタンス</returns>
    static CSVLoader* GetInstance() { static CSVLoader instance; return &instance; }

    /// <summary>
    /// データを取得
    /// </summary>
    /// <returns></returns>
    std::list<std::pair<std::string, CSVData>>* GetData() { return &fileData_; }

    /// <summary>
    /// ファイルを読み込む
    /// </summary>
    /// <param name="_fileName">ファイル名。oo.csv</param>
    /// <returns>読んだデータ</returns>
    CSVData* LoadFile(std::string _fileName);

    CSVLine* GetLine(std::string _fileName, std::string _ID);
    CSVLine* GetNewLine(std::string _fileName);

    void SaveFile();
    void SaveLine(std::string _fileName, CSVLine& _line);
    void SetDirectory(std::string _dir) { directory_ = _dir; }

private:
	CSVLoader() = default;
	~CSVLoader();

	std::string directory_ = "Resources/CSV/";

  std::list<std::pair<std::string, CSVData>> fileData_;
};