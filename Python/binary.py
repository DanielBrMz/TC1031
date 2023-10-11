def floatToBinary(number: float) -> str:
  integerPart = int(number)
  decimalPart = number - integerPart

  binaryIntegerPart: str = ""

  while integerPart:
    binaryIntegerPart = str(integerPart % 2) + binaryIntegerPart
    integerPart //= 2

  binaryDecimalPart: str = ""
  while decimalPart:
    decimalPart *=2
    bit = int(decimalPart)

    if bit == 1:
      decimalPart -= bit
      binaryDecimalPart += "1"
    else:
      binaryDecimalPart += "0"