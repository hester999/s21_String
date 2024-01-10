#include "s21_convert.h"

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#include "limits.h"
#include "s21_string.h"

long double s21_strtof(const char *str, char **pos, int width,
                       int *count_spec) {
  long double result = 0.0;
  long double fraction = 1.0;
  int decimal_point = 0;
  int exp_part = 0;
  int exp_sign = 1;
  int negative = 0;
  int temp = 0;

  while (str[temp] != ' ' && str[temp] != '\0') {
    temp++;
  }

  if (width == -100 || width > temp) {
    width = temp;
  }

  int i = 0;
  while (str[i] == ' ') {
    i++;
  }

  if ((str[i] == '-' || str[i] == '+') && (width > 0)) {
    negative = (str[i] == '-');
    i++;
    width--;
  }

  // Обработка специальных значений (inf, infinity, nan)
  if ((str[i] == 'i' || str[i] == 'I') &&
      (str[i + 1] == 'n' || str[i + 1] == 'N') &&
      (str[i + 2] == 'f' || str[i + 2] == 'F') && (width > 0)) {
    result = INFINITY;
    i += 3;
    width -= 3;
    if ((str[i] == 'i' || str[i] == 'I') &&
        (str[i + 1] == 'n' || str[i + 1] == 'N') &&
        (str[i + 2] == 'i' || str[i + 2] == 'I') &&
        (str[i + 3] == 't' || str[i + 3] == 'T') &&
        (str[i + 4] == 'y' || str[i + 4] == 'Y') && (width > 0)) {
      i += 5;
      width -= 5;
    }
    if (negative) result = -result;
  } else if ((str[i] == 'n' || str[i] == 'N') &&
             (str[i + 1] == 'a' || str[i + 1] == 'A') &&
             (str[i + 2] == 'n' || str[i + 2] == 'N') && (width > 0)) {
    result = NAN;
    i += 3;
    width -= 3;
    if (negative) result = -result;
  } else {
    while (str[i] && (width == -1 || i < width)) {
      if (str[i] >= '0' && str[i] <= '9') {
        result = result * 10.0 + (str[i] - '0');
        if (decimal_point) fraction *= 10.0;
      } else if (str[i] == '.' && !exp_part) {
        decimal_point = 1;
      } else if ((str[i] == 'e' || str[i] == 'E') && !exp_part) {
        exp_part = 1;
        i++;
        if ((str[i] == '-' || str[i] == '+') && (width == -1 || i < width)) {
          exp_sign = (str[i] == '-') ? -1 : 1;
          i++;
        }
        break;
      } else {
        break;
      }
      i++;
    }

    if (exp_part) {
      int exp_value = 0;
      while (str[i] && (width == -1 || i < width)) {
        if (str[i] >= '0' && str[i] <= '9') {
          exp_value = exp_value * 10 + (str[i] - '0');
          i++;
        } else {
          *count_spec = 0;
          break;
        }
      }
      result *= powl(10, exp_sign * exp_value);
    }
    if (negative) result = -result;
    result = result / fraction;
  }

  if (pos != s21_NULL) {
    *pos = (char *)str + i;
  }

  *count_spec += 1;
  return result;
}

long long int s21_atoi(const char *str, char **pos, int width,
                       int *count_spec) {
  long long int number = 0;
  int sign = 1;
  int i = 0;
  int temp = 0;
  int no_width = 0;
  int full_str = 0;
  int no_width_2 = width == 0;

  // Пропуск пробельных символов
  while (str[i] == ' ') {
    i++;
  }

  // Определение длины числа в строке
  while (str[temp] != '\0' && str[temp] != ' ') {
    temp++;
  }

  if (width >= temp) {
    full_str = 1;
  }

  if (width == -100) {
    width = temp;
    no_width = 1;
  }

  // Обработка знака
  if (str[i] == '-') {
    sign = -1;
    i++;
    width--;
  } else if (str[i] == '+') {
    sign = 1;
    i++;
    width--;
  }

  if (no_width) {
    width = temp;
  }
  if (full_str) {
    width = temp;
  }

  for (; str[i] != '\0' && str[i] != ' ' && (width > 0 || no_width_2); i++) {
    if (str[i] >= '0' && str[i] <= '9') {
      number = number * 10 + (str[i] - '0');
      if (number > (LLONG_MAX - number) / 10) {
        number = (sign == 1) ? LLONG_MAX : LLONG_MIN;
        break;
      }
    } else {
      *count_spec = 0;
      break;
    }
    width--;
  }

  *pos = (char *)(str + i);
  *count_spec += 1;
  return number * sign;
}

int s21_hex_convert(const char *str, char **pos, int *width, int *count_spec) {
  int res = 0;
  int num = 0;
  int i = 0;
  int negative_num = 1;
  int temp = 0;
  int no_width = 0;
  int full_str = 0;
  int no_width_2 = *width == 0;

  while (str[temp] != ' ' && str[temp] != '\0') {
    temp++;
  }
  if (*width >= temp) {
    full_str = 1;
  }

  if (*width == -100) {
    *width = temp;
    no_width = 1;
  }

  // Пропуск начальных пробелов и знаков
  while (str[i] == ' ') {
    i++;
  }
  if (str[i] == '-') {
    negative_num = -1;
    i++;
    (*width)--;

  } else if (str[i] == '+') {
    i++;
  }

  if (str[i] == '0' && (str[i + 1] == 'x' || str[i + 1] == 'X') &&
      (i < *width)) {
    i += 2;
    *width -= 2;
  }

  if (no_width) {
    *width = temp;
  }
  if (full_str) {
    *width = temp;
  }

  for (; str[i] != '\0' && str[i] != ' ' && (*width > 0 || no_width_2); i++) {
    if (str[i] >= '0' && str[i] <= '9') {
      num = str[i] - '0';
    } else if (str[i] >= 'a' && str[i] <= 'f') {
      num = 10 + (str[i] - 'a');
    } else if (str[i] >= 'A' && str[i] <= 'F') {
      num = 10 + (str[i] - 'A');
    } else {
      *count_spec = 0;
      break;
    }
    (*width)--;
    res = res * 16 + num;
  }

  *pos = (char *)(str + i);
  res *= negative_num;
  *count_spec += 1;

  return res;
}

int s21_octal_convert(const char *str, char **pos, int width, int *count_spec) {
  int res = 0;
  int num = 0;
  int i = 0;
  int negative_num = 1;
  int temp = 0;
  // Пропуск начальных пробелов и знаков
  while (str[i] == ' ') {
    i++;
  }

  for (int i = 0; str[i] != ' ' && str[i] != '\0'; i++) {
    temp++;
  }

  if (width == -100 || width > temp) {
    width = temp;
  }

  if (str[i] == '-') {
    negative_num = -1;
    i++;
    width--;
  } else if (str[i] == '+') {
    i++;
    width--;
  }

  if (str[i] == '0') {
    i++;
    width--;
  }

  for (; str[i] != '\0' && str[i] != ' ' && (width > 0); i++) {
    if (str[i] >= '0' && str[i] <= '7') {
      num = str[i] - '0';
    } else {
      *count_spec = 0;
      break;
    }

    res = res * 8 + num;
    width--;
  }

  *pos = (char *)(str + i);
  res *= negative_num;
  *count_spec += 1;
  return res;
}

unsigned long long s21_get_pointer(const char *str, char **pos, int width,
                                   int *count_spec) {
  unsigned long long res = 0;
  int num = 0;
  int i = 0;
  int temp = 0;
  int no_width = 0;
  int full_str = 0;
  int no_width_2 = width == 0;
  int isNegative = 0;  // Флаг для отрицательного числа

  while (str[i] == ' ') {
    i++;
  }

  // Проверка на отрицательный знак
  if (str[i] == '-') {
    isNegative = 1;
    i++;
    if (width != -100) width--;  // Уменьшаем width, если он задан
  }

  while (str[temp] != '\0' && str[temp] != ' ') {
    temp++;
  }

  if (width >= temp) {
    full_str = 1;
  }

  if (width == -100) {
    width = temp;
    no_width = 1;
  }

  if (no_width) {
    width = temp;
  }
  if (full_str) {
    width = temp;
  }

  if (str[i] == '0' && (str[i + 1] == 'x' || str[i + 1] == 'X') &&
      (i < width)) {
    i += 2;
    width -= 2;
  }
  for (; str[i] != '\0' && str[i] != ' ' && (width > 0 || no_width_2); i++) {
    if (str[i] >= '0' && str[i] <= '9') {
      num = str[i] - '0';
    } else if (str[i] >= 'a' && str[i] <= 'f') {
      num = 10 + (str[i] - 'a');
    } else if (str[i] >= 'A' && str[i] <= 'F') {
      num = 10 + (str[i] - 'A');
    } else {
      *count_spec = 0;
      break;  // Некорректный символ, прерываем обработку
    }
    width--;
    res = res * 16 + num;
  }

  // Преобразование в отрицательное значение, если необходимо
  if (isNegative) {
    res = ~(res - 1);
  }

  *pos = (char *)(str + i);
  *count_spec = +1;
  return res;
}

int s21_convert_str_to_int_auto_base(const char *str, char **pos, int width,
                                     int *count_spec) {
  int result = 0;
  int i = 0;
  while (str[i] == ' ' || str[i] == '+' || str[i] == '-') {
    i++;
  }

  if (str[i] == '0') {
    if (str[i + 1] == 'x' || str[i + 1] == 'X') {
      // Число в шестнадцатеричной системе
      result = s21_hex_convert(str, pos, &width, count_spec);
    } else {
      // Число в восьмеричной системе
      result = s21_octal_convert(str, pos, width, count_spec);
    }
  } else {
    // Число в десятичной системе
    result = s21_atoi(str, pos, width, count_spec);
  }
  return result;
}

unsigned long long s21_get_unsigned_num(const char *str, char **pos, int width,
                                        int *count_spec) {
  unsigned long long result = 0;
  int temp = 0;
  int negative = 0;

  while (*str == ' ') {
    str++;
  }

  if (*str == '-') {
    negative = 1;
    str++;
  }

  for (int i = 0; str[i] != ' ' && str[i] != '\0'; i++) {
    temp++;
  }
  if (width == -100 || width > temp) {
    width = temp;
  }

  int check = s21_support_to_ull(str);

  if (check == 1) {
    result = ULLONG_MAX;
    *pos = (char *)str + temp;
    return result;
  }

  while (*str >= '0' && *str <= '9' && (width > 0)) {
    // Проверка на переполнение перед умножением
    if (result > ULLONG_MAX / 10 ||
        (result == ULLONG_MAX / 10 &&
         (unsigned long long)(*str - '0') > ULLONG_MAX % 10)) {
      // Обработка переполнения
      result = ULLONG_MAX;
      break;
    }

    result = result * 10 + (*str - '0');
    str++;
    width--;
  }

  // В случае отрицательного числа, возвращаем ULLONG_MAX
  if (negative) {
    result = ULLONG_MAX;
  }

  if (pos != s21_NULL) {
    *pos = (char *)str;
  }

  *count_spec += 1;
  return result;
}

int s21_support_to_ull(const char *str) {
  unsigned long long result = 0;

  // Пропуск начальных пробелов
  while (*str == ' ') {
    str++;
  }

  // Чтение и конвертация числа
  while (*str >= '0' && *str <= '9') {
    // Проверка на переполнение перед умножением
    if (result > ULLONG_MAX / 10 ||
        (result == ULLONG_MAX / 10 &&
         (unsigned long long)(*str - '0') > ULLONG_MAX % 10)) {
      return 1;  // Переполнение обнаружено
    }

    result = result * 10 + (*str - '0');
    str++;
  }

  return 0;  // Переполнение не обнаружено
}