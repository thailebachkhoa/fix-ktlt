#include "tay_nguyen_campaign.h"

////////////////////////////////////////////////////////////////////////
/// STUDENT'S ANSWER BEGINS HERE
/// Complete the following functions
/// DO NOT modify any parameters in the functions.
////////////////////////////////////////////////////////////////////////

const int MAX_LINES = 5;
const int MAX_LINE_LENGTH = 100;

namespace spclasses
{
  // Helper functions and variables can be defined here
  class Task0
  {
  public:
    void extractNumbers(const string &str, int arr[], int maxSize)
    {
      // input: "10,20,30,40,50"
      // output arr[] = {10, 20, 30, 40, 50}
      // maxsize = 5 (nums elements, in this case is 17 )
      // format là [num1, num2, num3, num4, num5,] thì lại chấp nhận :(((
      stringstream ss(str);
      string token;
      int count = 0; // Reset count
      
      while (getline(ss, token, ',') ) // && count < maxSize
      {
        // check if token is number
        for (size_t i = 0; i < token.size(); i++)
        {
          if (!isdigit(token[i]))
          {
            throw exception();
          }
        }
        arr[count++] = stoi(token); // Convert and store in the array
      }
      if (count != maxSize)
      {
        throw exception();
      } 
    }
    string removeBrackets(const string &input)
    {
      if (!input.empty() && input.front() == '[' && input.back() == ']')
        return input.substr(1, input.size() - 2);
      // lấy chuỗi con từ vị trí 1 đến vị trí gần cuối -> loại bỏ dấu ngoặc
      return input;
    }
    
    void extractNumbers(const string& str, int& num1, int& num2) {
      stringstream ss(str);
  
      // Đọc hai số
      if (!(ss >> num1 >> num2)) {
          throw exception();
      }
  
      // Kiểm tra có còn dữ liệu dư thừa không
      string leftover;
      if (ss >> leftover) {
          throw exception();
      }
  }
    void extractNumbers(const string&str, int &num)
    {
      stringstream ss(str);
      if (!(ss >> num))
      {
        throw exception();
      }
      string leftover;
      if (ss >> leftover)
      {
        throw exception();
      }
    }
  };
  class Task1
  {
  public:
    int *valueArr = new int[17];
    Task1()
    {
      valueArr[0] = 1;
      valueArr[1] = 2;
      valueArr[2] = 3;
      valueArr[3] = 4;
      valueArr[4] = 5;

      valueArr[5] = 7;
      valueArr[6] = 8;
      valueArr[7] = 9;
      valueArr[8] = 10;

      valueArr[9] = 12;
      valueArr[10] = 15;
      valueArr[11] = 18;
      valueArr[12] = 20;

      valueArr[13] = 30;
      valueArr[14] = 40;
      valueArr[15] = 50;
      valueArr[16] = 70;
    }
    ~Task1()
    {
      delete[] valueArr;
    }
  };
  class Task2
  {
  public:
    string HashID(int id)
    {
      if (id == 0 || id == 1 || id == 2) 
        return "DECOY";
      if (id == 3)
        return "Buon Ma Thuot";
      if (id == 4)
        return "Duc Lap";
      if (id == 5)
        return "Dak Lak";
      if (id == 6)
        return "National Route 21";
      if (id == 7)
        return "National Route 14";
      else 
        return "INVALID";
    }
    int max(int a, int b, int c)
    {
      return a > b ? (a > c ? a : c) : (b > c ? b : c);
    }
  };
  class Task3
  {
  public:
  };
  // reset fucs
  void resetExp(int &EXP)
  {
    if (EXP < 0)
      EXP = 0;
    if (EXP > 600)
      EXP = 600;
  }
  void resetT(int &T)
  {
    if (T < 0)
      T = 0;
    if (T > 3000)
      T = 3000;
  }
  void resetE(int &E)
  {
    if (E < 0)
      E = 0;
    if (E > 99)
      E = 99;
  }
  void resetLF(int LF[])
  {
    for (int i = 0; i < 17; i++)
    {
      if (LF[i] < 0)
        LF[i] = 0;
      if (LF[i] > 1000)
        LF[i] = 1000;
    }
  }
  // common functions

  char shiftLeft(char c, int shift)
  {
    if (isupper(c))
    {
      // Xử lý chữ in hoa
      return 'A' + ((c - 'A' + shift ) % 26);
    }
    else if (islower(c))
    {
      // Xử lý chữ in thường
      return 'a' + ((c - 'a' + shift ) % 26);
    }
    // Nếu không phải chữ cái, không thay đổi
    return c;   
    
  }

}

void quicksort(int arr[], int l, int r)
{
  /*
  Ý tưởng: Chọn pivot là phần tử ở giữa
  Chọn 2 đầu l, r từ 2 phía của mảng
  Nếu arr[l] đúng vị trí thì l++
  Nếu arr[r] đúng vị trí thì r--
  -> mục đích là tìm các phần tử sai vị trí và đổi ch
  => sẽ có 2 mảng con bên trái và bên phải pivot được sắp đúng chỗ -> đệ quy
  */
  if (l >= r)
    return;
  int pivot = arr[(l + r) / 2];
  int i = l, j = r;
  while (i < j) // mới fix 
  {
    while (arr[i] < pivot)
      i++;
    while (arr[j] > pivot)
      j--;
    if (i <= j)
    {
      swap(arr[i], arr[j]);
      i++;
      j--;
    }
  }
  quicksort(arr, l, j);
  quicksort(arr, i, r);
}

// Task 0: Read input file
bool readFile(
    const string &filename,
    int LF1[], int LF2[],
    int &EXP1, int &EXP2,
    int &T1, int &T2, int &E)
{
  ////////////////////// Read data from the file //////////////////
  char data[MAX_LINES][MAX_LINE_LENGTH]; // the data is in this array (distracted)
  int numLines = 0;

  // open file
  ifstream ifs(filename);
  if (!ifs.is_open())
    return false;

  while (numLines < MAX_LINES && ifs.getline(data[numLines], MAX_LINE_LENGTH))
  {
    numLines++;
  }
  // lưu ý cú pháp ifs.getline(data[numLines], MAX_LINE_LENGTH): đọc dữ liệu từ file vào mảng data
  ifs.close(); // close

  // check exceptions
  if (numLines < MAX_LINES)
    return false;

  /////////////////////////////////////////////////////////////////

  // TODO: Extract values from the `data` array and store them in respective variables
  spclasses::Task0 task0;
  try
  { // Extract LF1
    // convert char arr / string to int arr
    string LF1_str = data[0];
    task0.extractNumbers(task0.removeBrackets(LF1_str), LF1, 17);
    // Extract LF2
    // convert char to int arr
    string LF2_str = data[1];
    task0.extractNumbers(task0.removeBrackets(LF2_str), LF2, 17);
    // Extract EXP1, EXP2
    task0.extractNumbers(data[2], EXP1, EXP2);
    // Extract T1, T2
    task0.extractNumbers(data[3], T1, T2);
    // Extract E
    task0.extractNumbers(data[4], E);
  }
  catch (exception &e)
  {
    return false;
  }

  // Reset values
  spclasses::resetLF(LF1);
  spclasses::resetLF(LF2);
  spclasses::resetExp(EXP1);
  spclasses::resetExp(EXP2);
  spclasses::resetT(T1);
  spclasses::resetT(T2);
  spclasses::resetE(E);

  return true;
}

// Task 1
int gatherForces(int LF1[], int LF2[])
{
  // TODO: Implement this function
  spclasses::Task1 task1;
  int *weightarr = task1.valueArr;
  int sum1 = 0, sum2 = 0;
  for (int i = 0; i < 17; i++)
  {
    sum1 += LF1[i] * weightarr[i];
    sum2 += LF2[i] * weightarr[i];
  }
  return sum1 + sum2;
}

// Task 2
string determineRightTarget(const string &target)
{
  // TODO: Implement this function
  spclasses::Task2 task2; 
  // create arr to store nums
  DlinkedList *dlist = new DlinkedList();
  // Extract numbers from the target string
  for (size_t i = 0; i < target.length();)
  {
    // trường hợp 100
    if ( i + 2 < target.length() && target[i] == '1' && target[i + 1] == '0' && target[i + 2] == '0' )
    {
      dlist->push_back(100); 
      i += 3;
      continue;
    }
    // 0 -> 99
    if (isdigit(target[i]))
    {
      // Chuyển ký tự số sang số nguyên
      int num = target[i] - '0';
      // Kiểm tra ký tự tiếp theo nếu là số thì ghép thành số hai chữ số
      if (i + 1 < target.length() && isdigit(target[i + 1]))
      {
        num = num * 10 + (target[i + 1] - '0');
        i += 2;
      }
      else i++;
      // cout << num << endl;
      dlist->push_back(num);
    }
    // Ignore other characters
    else i++;
    
  }
  // Determine the right target
  string result = "INVALID"; // cout << dlist->size() << endl;
  if (dlist->size() == 1) result = task2.HashID(dlist->pop_back());
  if (dlist->size() == 2)
  {
    int num1 = dlist->pop_back(), num2 = dlist->pop_back();
    int id = (num1 + num2) % 5 + 3;
    result = task2.HashID(id);
  }
  if (dlist->size() == 3)
  {
    int num1 = dlist->pop_back(), num2 = dlist->pop_back(), num3 = dlist->pop_back();
    int id = task2.max(num1, num2, num3) % 5 + 3; 
    result = task2.HashID(id);
  }
  
  delete dlist;return result;
}

string Ceasar_Cipher(string message, int EXP1, int EXP2)
{
  // shift the message
  int shift = (EXP1 + EXP2) % 26;
  string cipher = message;
  for (int i = 0; i < message.length(); i++)
  {
    cipher[i] = spclasses::shiftLeft(message[i], shift);
    // nếu cipher không phải chữ cái thì return INVALID
    if (!isalpha(cipher[i]) && cipher[i] != ' ' && !isdigit(cipher[i]))
      return "INVALID";
  }
  //cout << cipher << endl;
  // convert message to lower case
  for (int i = 0; i < message.length(); i++)
  {
    cipher[i] = tolower(cipher[i]);
  }

  // return block
  {
  if (cipher == "kon tum")
    return "Kon Tum";
  if (cipher == "pleiku")
    return "PleiKu";
  if (cipher == "gia lai")
    return "Gia Lai";
  if (cipher == "buon ma thuot")
    return "Buon Ma Thuot";
  if (cipher == "duc lap")
    return "Duc Lap";
  if (cipher == "dak lak")
    return "Dak Lak";
  if (cipher == "national route 21")
    return "National Route 21";
  if (cipher == "national route 14")
    return "National Route 14";
  return "INVALID";
  }
}
string reverseStr(const string message)
{
  // reverse string
  string reversed = message;
  for (int i = 0; i < message.length(); i++)
  {
    reversed[i] = message[message.length() - 1 - i];
  }
  // convert message to lower case
  for (int i = 0; i < message.length(); i++)
  {
    reversed[i] = tolower(reversed[i]);
  }
  // return block
  {
  if (reversed == "kon tum")
    return "Kon Tum";
  if (reversed == "pleiku")
    return "PleiKu";
  if (reversed == "gia lai")
    return "Gia Lai";
  if (reversed == "buon ma thuot")
    return "Buon Ma Thuot";
  if (reversed == "duc lap")
    return "Duc Lap";
  if (reversed == "dak lak")
    return "Dak Lak";
  if (reversed == "national route 21")
    return "National Route 21";
  if (reversed == "national route 14")
    return "National Route 14";
  return "INVALID";
  }
}
string decodeTarget(const string &message, int EXP1, int EXP2)
{
  // TODO: Implement this function
  if (EXP1 >= 300 && EXP2 >= 300)
    return Ceasar_Cipher(message, EXP1, EXP2);
  else
    return reverseStr(message);
}

// Task 3
void manageLogistics(int LF1, int LF2, int EXP1, int EXP2, int &T1, int &T2, int E)
{
  // TODO: Implement this function
  if (E >= 60) return;
  // reset before calculation
  spclasses::resetExp(EXP1); 
  spclasses::resetExp(EXP2);
  spclasses::resetT(T1);
  spclasses::resetT(T2);
  spclasses:: resetE(E);
  
  // chia cases
  if (E == 0) { 
  double deltaT1 = ((LF1 * 1.0 / (LF1 * 1.0 + LF2)) * (T1 + T2) ) * (1 + (EXP1 * 1.0 - EXP2) / 100.0);
  double deltaT2 = (T1 + T2) - deltaT1;
  T1 += ceil (deltaT1); spclasses::resetT(T1);
  T2 += ceil(deltaT2); spclasses::resetT(T2);
  }

  if (E >= 1 && E <= 9)
  {
    /*
    – Quân đoàn 1 mất (E × 1%) tiếp tế.
    – Quân đoàn 2 mất (E × 0.5%) tiếp tế
    */
    T1 = ceil(T1 - E * 0.01 * T1);
    spclasses::resetT(T1);
    T2 = ceil(T2 - E * 0.005 * T2);
    spclasses::resetT(T2);
  }
  if (E >= 10 && E <= 29)
  {
    /*
    – Mỗi quân đoàn nhận thêm (E × 50) đơn vị tiếp tế
    */
    T1 = T1 + E * 50;
    spclasses::resetT(T1);
    T2 = T2 + E * 50;
    spclasses::resetT(T2);
  }
  // 30 59
  if (E >= 30 && E <= 59)
  {
    /*
    Quân đoàn 1 được tăng cường (E × 0.5%) tiếp tế.
    Quân đoàn 2 chỉ nhận được (E × 0.2%) tiếp tế
    */
    T1 = ceil(T1 + E * 0.005 * T1);
    spclasses::resetT(T1);
    T2 = ceil(T2 + E * 0.002 * T2);
    spclasses::resetT(T2);
  }
}

// Task 4
int planAttack(int LF1, int LF2, int EXP1, int EXP2, int T1, int T2, int battleField[10][10])
{
  // TODO: Implement this function
  double S = (LF1 + LF2) + (EXP1 + EXP2) * 5.0 + (T1 + T2) * 2.0;

  for (int i = 0; i < 10; i++)
  {
    for (int j = 0; j < 10; j++)
    {
      // if (i % 2 == 1)
      //   S = ceil(S - battleField[i][j] * 3.0 / 2.0);
      // else
      //   S = ceil(S - battleField[i][j] * 2.0 / 3.0);
      if (i % 2 == 1)
        S = S - battleField[i][j] * 3.0 / 2.0;
      else
        S = S - battleField[i][j] * 2.0 / 3.0;
    }
  }
  return ceil(S); // output same to material
  // return S; // output same to testcase
}

// Task 5
void dfs(int start, int count, int currentSum, int shortfall, int &bestSum, int *cells)
{
  // Cắt nhánh đặc biệt 1: Nếu tổng hiện tại đã bằng shortfall, không cần duyệt nữa
  if (bestSum == shortfall) return;
  // chọn đủ 5 ô thì check
  if (count == 5)
  {
    if (currentSum >= shortfall)
      bestSum = min(bestSum, currentSum);
    return;
  }
  int left = 5 - count; // số ô cần chọn thêm
  // Cắt nhánh đb 2: Nếu số ô còn lại trong vector không đủ để chọn, dừng đệ quy
  if (25 - start < left)
    return;
  // Cắt nhánh 1: Dự đoán tổng nhỏ nhất có thể đạt được từ các ô chưa chọn, cận dưới
  {
  int minExtension = 0;
  for (int i = start; i < start + left; i++)
  {
    minExtension += cells[i];
  }
  // Nếu tổng nhỏ nhất khả dĩ vượt quá bestSum đã tìm được, không cần duyệt nhánh này nữa
  if (currentSum + minExtension > bestSum)
    return;
  }
  // Cắt nhánh 2: Kiểm tra xem branch này có thể đạt đủ shortfall không, cận trên
  {
  int maxExtension = 0;
  for (int i = 25 - left; i < 25; i++)
  {
    maxExtension += cells[i];
  }
  // Nếu tổng lớn nhất khả dĩ vẫn chưa đủ shortfall, branch này không bao giờ thỏa
  if (currentSum + maxExtension < shortfall)
    return;
  }
  // Duyệt qua các phần tử khả dĩ bắt đầu từ vị trí 'start'
  for (int i = start; i < 25; i++)
  {
    if (currentSum + cells[i] > bestSum)
      break;
    dfs(i + 1, count + 1, currentSum + cells[i], shortfall, bestSum, cells);
  }
}
int resupply(int shortfall, int supply[5][5])
{
  // TODO: Implement this function
  int cells[25];         // 5x5 matrix to 1D array
  int bestSum = 9999999; // init bestSum
  // Bước 1: Chuyển ma trận 5x5 thành vector gồm 25 giá trị
  for (int i = 0; i < 5; i++)
  {
    for (int j = 0; j < 5; j++)
    {
      cells[i * 5 + j] = supply[i][j];
    }
  }
  // Bước 2: Sắp xếp mảng theo thứ tự tăng dần
  quicksort(cells, 0, 24);
  // Bước 3: Gọi hàm đệ quy để duyệt các tổ hợp
  dfs(0, 0, 0, shortfall, bestSum, cells);
  // Trả về tổng của 5 ô được chọn
  return bestSum;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////
