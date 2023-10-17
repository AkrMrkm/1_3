/**
* @file doublyLinkedList.h
* @brief 双方向リストクラス
* @author 村上輝
* @date 2023/10/17/15:00
* @details 課題1_3「双方向リストのテンプレート化」
*/

#pragma once

/**
* @brief 双方向リストクラス
*/
template<typename DATA>
class DoublyLinkedList
{
private:
	/**
	* @brief ノード
	*/
	struct Node
	{
		//! 前ノード
		Node* m_prev;

		//! 次ノード
		Node* m_next;

		//! データ
		DATA m_data;

		/**
		* @brief 引数無しコンストラクタ
		*/
		Node() : m_prev(nullptr), m_next(nullptr), m_data() {}

		/**
		* @brief 引数付きコンストラクタ
		* @param[in] data 要素が持つデータ
		*/
		Node(const DATA data) : m_prev(nullptr), m_next(nullptr), m_data(data) {}
	};

	//! ダミーノード
	Node* m_DummyNode;

	//! データ数
	int m_DataNum;

public:

	/**
	* @brief コンストイテレータクラス
	* @details 双方向リストクラスのインナークラス
	*/
	class ConstIterator
	{
	private:
		//! 双方向リストクラスをfriend指定
		friend class DoublyLinkedList;

		//! ノードへのポインタ
		Node* m_Node;

		//! リストのポインタ
		const DoublyLinkedList* m_List;

	public:

		/**
		* @brief 引数無しコンストラクタ
		*/
		inline ConstIterator();

		/**
		* @brief 引数付きコンストラクタ
		* @param[in] node イテレータの指す要素
		* @param[in] list リストの参照
		*/
		inline ConstIterator(Node* node, const DoublyLinkedList* list);

		/**
		* @brief イテレータの先頭に向かってひとつ進める(前置)
		* @return 先頭にひとつ進めたイテレータを返す
		* @details ノードの参照が無かったらorダミーノードであったらassert
		*/
		inline ConstIterator& operator--();

		/**
		* @brief イテレータの先頭に向かってひとつ進める(後置)
		* @return 先頭にひとつ進めたイテレータを返す
		* @details ノードの参照が無かったらorダミーノードであったらassert
		*/
		inline ConstIterator operator--(int);

		/**
		* @brief イテレータの末尾に向かってひとつ進める(前置)
		* @return 末尾にひとつ進めたイテレータを返す
		* @details ノードの参照が無かったらorダミーノードであったらassert
		*/
		inline ConstIterator& operator++();

		/**
		* @brief イテレータの末尾に向かってひとつ進める(後置)
		* @return 末尾にひとつ進めたイテレータを返す
		* @details ノードの参照が無かったらorダミーノードであったらassert
		*/
		inline ConstIterator operator++(int);

		/**
		* @brief イテレータの指す要素を取得する(const)
		* @return イテレータの指す成績データを返す
		* @details ノードの参照が無かったらorダミーノードであったらassert
		*/
		inline const DATA operator*() const;

		/**
		* @brief コピーコンストラクタ
		* @param[in] it コピー元のコンストイテレータ
		*/
		inline ConstIterator(const ConstIterator& it);

		/**
		* @brief 代入を行う
		* @param[in] it 代入するイテレータ
		* @details イテレータのノードを代入する
		*/
		inline ConstIterator& operator=(const ConstIterator& it);

		/**
		* @brief 同一か比較する
		* @param[in] it 同一か比較するイテレータ
		* @return イテレータの指す要素が同一であればtrueを返す
		*/
		inline bool operator==(const ConstIterator& it);

		/**
		* @brief 異なるか比較する
		* @param[in] it 異なるか比較するイテレータ
		* @return イテレータの指す要素が異なればtrueを返す
		*/
		inline bool operator!=(const ConstIterator& it);

		/**
		* @brief イテレータの指すノードがダミーノードか判別する
		* @return もしダミーノードであればtrueを返す
		* @details テストでダミーノードと比較する際に使用
		*/
		inline bool CheckDummyNode();
	};

	/**
	* @brief イテレータクラス
	* @details コンストイテレータクラスの派生クラス
	*/
	class Iterator : public ConstIterator
	{
	public:
		/**
		* @brief 引数無しコンストラクタ
		*/
		inline Iterator();

		/**
		* @brief 引数付きコンストラクタ
		* @param[in] node イテレータの指す要素
		* @param[in] list リストの参照
		*/
		inline Iterator(Node* node, const DoublyLinkedList* list);

		/**
		* @brief イテレータの指す要素を取得する(非const)
		* @return イテレータの指す成績データを返す
		* @details ノードの参照が無かったらorダミーノードであったらassert
		*/
		inline DATA& operator*();
	};

	/**
	* @brief 双方向リストクラスのコンストラクタ
	* @details データ数、ダミーノードを初期化\n
			   リストが空の場合、ダミーノードの前後はダミーノード自身を参照\n
	*/
	inline DoublyLinkedList();

	/**
	* @brief 双方向リストクラスのデストラクタ
	* @details 先頭から末尾までdelete
	*/
	virtual inline ~DoublyLinkedList();

	/**
	* @brief データ数の取得
	* @return リストのデータの総数を返す
	*/
	inline int GetDataNum() const;

	/**
	* @brief データの挿入
	* @param[in] it 挿入したい位置のイテレータ
	* @param[in] data 挿入したい成績データ
	* @return bool(挿入が成功すればtrue、失敗すればfalse)
	* @details イテレータの指すノードの前に挿入する
	*/
	inline bool Insert(ConstIterator& it, const DATA& data);

	/**
	* @brief データの追加
	* @param[in] data 追加したい成績データ
	* @details 末尾にデータの追加
	*/
	inline void PushBack(const DATA& data);

	/**
	* @brief データの削除
	* @param[in] it 削除したい位置のイテレータ
	* @return 削除に失敗したらfalse、成功したらtrueを返す
	* @details イテレータの指すノードを削除\n
				データ数が0、イテレータの指すノードがダミーノード、別リストを指すイテレータであれば何も行わない\n
	*/
	inline bool Remove(ConstIterator& it);

	/**
	* @brief 先頭イテレータ取得
	* @return ダミーノードの次のノード(先頭のイテレータを返す)
	*/
	inline Iterator GetBegin();

	/**
	* @brief 先頭コンストイテレータ取得
	* @return ダミーノードの次のノード(先頭のコンストイテレータを返す)
	*/
	inline ConstIterator GetCBegin() const;

	/**
	* @brief 末尾イテレータ取得
	* @return ダミーノードを返す
	*/
	inline Iterator GetEnd();

	/**
	* @brief 末尾コンストイテレータ取得
	* @return ダミーノードを返す
	*/
	inline ConstIterator GetCEnd() const;
};

#include "doublyLinkedList.inl"
