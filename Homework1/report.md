# 41443115

# 作業一

## Problem 1：Ackermann's Function

### 1. 解題說明

#### 問題描述

本題要求我寫出阿克曼函數並寫兩種版本：

1. 遞迴

2. 非遞迴

#### 解題策略

1. **遞迴版本 ：** 

   直接對應數學定義的三個條件自我呼叫就好。

2. **非遞迴版本** ： \
   需手動模擬遞迴

   * 將當前的 $m$ 推入堆疊，變數 $n$ 作為當前數值。

   * 遇到 $m = 0$ 時計算 $n = n + 1$。

   * 遇到 $n = 0$ 時將 $m - 1$ 推入堆疊，重設 $n = 1$。

   * 遇到一般情況時，先將外層的 $m - 1$ 推入堆疊，再將內層的 $m$ 推入堆疊，並將 $n$ 減 1，藉由後進先出的順序依序解開計算。

### 2. 程式實作

#### 遞迴版本 (`problem1/algorithm1.cpp`)

```
#include <iostream>
using namespace std;

int ack(int m, int n) {
    if (m == 0) 
        return n + 1;
    else if (n == 0) 
        return ack(m - 1, 1);
    else 
        return ack(m - 1, ack(m, n - 1));
}

int main() {
    int m1, n1;
    cin >> m1 >> n1;
    cout << ack(m1, n1) << endl;
    return 0;
}

```

#### 非遞迴版本 (`problem1/nalgorithm1.cpp`)

```
#include <iostream>
#include <stack>
using namespace std;

int ack(int m, int n) {
    stack<int> s1;
    s1.push(m);

    while (!s1.empty()) {
        m = s1.top();
        s1.pop();

        if (m == 0) {
            n += 1;
        } else if (n == 0) {
            s1.push(m - 1);
            n = 1;
        } else {
            s1.push(m - 1);
            s1.push(m);
            n -= 1;
        }
    }
    return n;
}

int main() {
    int m1, n1;
    cin >> m1 >> n1;
    cout << ack(m1, n1) << endl;
    return 0;
}

```

### 3. 效能分析

阿克曼函因會大量自我呼叫，成長速度極度驚人：

1. **時間複雜度**：
   無法以多項式表示。當 $m \ge 4$ 時，計算次數急遽膨脹，屬於極高階的非原始遞迴函數。

2. **空間複雜度**：

   * **遞迴版本**：空間複雜度取決於系統 Call Stack 的深度。當 $m$ 稍大時即會耗盡呼叫堆疊而導致 Stack Overflow。

   * **非遞迴版本**：空間複雜度取決於手動維護的 `std::stack` 中最大儲存元素個數，佔用 Heap/Data 區域，相較系統堆疊能承受更大量的元素，但同樣受限於記憶體大小。

### 4. 測試與驗證

| 測試案例 | 輸入 ($m, n$) | 預期輸出 | 實際輸出 | 
| ----- | ----- | ----- | ----- | 
| 測試一 | `0 0` | `1` | `1` | 
| 測試二 | `0 3` | `4` | `4` | 
| 測試三 | `1 2` | `4` | `4` | 
| 測試四 | `2 3` | `9` | `9` | 
| 測試五 | `3 2` | `29` | `29` | 

實際編譯與執行結果：
兩種版本輸入 `2 3` 皆正確輸出 `9`，輸入 `3 2` 皆輸出 `29`，驗證結果完全相符。

### 5. 申論及開發報告

透過實作阿克曼函數，深入體會到了遞迴的本質：

* 遞迴的優勢在於能極為精簡地表達數學定義與狀態轉換。

* 然而，巢狀遞迴（如 $A(m-1, A(m, n-1))$）會在系統呼叫堆疊中累積龐大的未決狀態。

* 改寫為非遞迴版本時，使用堆疊（Stack）來手動管理狀態，能清晰看到每一次計算暫存、取出與更新的生命週期，深刻理解了編譯器與作業系統背後底層處理函式呼叫的機制。

## Problem 2：Powerset

### 1. 解題說明

#### 問題描述

若集合 $S$ 含有 $n$ 個元素，其冪集（Powerset）是包含 $S$ 的所有子集合的集合（包括空集合與自身）。
若集合元素個數為 $n$，其冪集的子集合總數必為 $2^n$ 個。

#### 解題策略

採用二元決策樹（Binary Decision Tree）與回溯概念進行遞迴搜尋：

1. 對於集合中的每一個元素，都有兩種可能：「**不選**」或「**選入**」。

2. 使用遞迴索引 `index` 依序推進。

3. 終止條件：當 `index` 達到集合大小 $n$ 時，表示所有元素皆已決定好狀態，將當前組合輸出。

### 2. 程式實作 (`problem2/problem2.cpp`)

```
#include <iostream>
using namespace std;

char S[] = { 'a', 'b', 'c' };
const int n = 3;
bool chosen[n];
bool isFirstSubset = true;

void powerset(int index) {
    // 終止條件：所有元素均已考慮完畢
    if (index == n) {
        if (!isFirstSubset) cout << ", ";
        isFirstSubset = false;

        cout << "(";
        bool firstElement = true;
        for (int i = 0; i < n; i++) {
            if (chosen[i]) {
                if (!firstElement) cout << ", ";
                cout << S[i];
                firstElement = false;
            }
        }
        cout << ")";
        return;
    }

    // 決策 1：不選擇當前元素
    chosen[index] = false;
    powerset(index + 1);

    // 決策 2：選擇當前元素
    chosen[index] = true;
    powerset(index + 1);
}

int main() {
    cout << "powerset(S) = {";
    powerset(0);
    cout << "}" << endl;
    return 0;
}

```

### 3. 效能分析

1. **時間複雜度**：$O(n \times 2^n)$
   共有 $2^n$ 個子集合，每一個子集合在列印時需遍歷長度為 $n$ 的布林陣列。

2. **空間複雜度**：$O(n)$
   遞迴最大深度為 $n$，輔助記錄陣列 `chosen` 大小為 $n$。

### 4. 測試與驗證

| 測試案例 | 輸入集合 $S$ | 預期子集合數量 | 輸出驗證 | 
| ----- | ----- | ----- | ----- | 
| 測試一 | `{a}` | $2^1 = 2$ | `{(), (a)}` | 
| 測試二 | `{a, b}` | $2^2 = 4$ | `{(), (b), (a), (a, b)}` | 
| 測試三 | `{a, b, c}` | $2^3 = 8$ | `{(), (c), (b), (b, c), (a), (a, c), (a, b), (a, b, c)}` | 

實際執行輸出：

```
powerset(S) = {(), (c), (b), (b, c), (a), (a, c), (a, b), (a, b, c)}

```

輸出共 8 個子集合，完整包含所有組合且無重複。

### 5. 申論及開發報告

Powerset 是經典的組合窮舉問題。使用遞迴的方式將「選」與「不選」分為兩個分支展開，邏輯非常自然。在寫這題時體會到：

* 終止條件（Base Case）必須準確設定在 `index == n`，避免陣列越界。

* 透過布林陣列記錄狀態，能省去繁複的字串拼接開銷，結構清晰好維護。

## 作業總結

本次作業聚焦於遞迴思維與堆疊應用：

1. 在 Problem 1 中，學會利用堆疊模擬遞迴

2. 在 Problem 2 中，利用分枝遞迴解決了 Powerset 問題，掌握了二元決策邏輯。
