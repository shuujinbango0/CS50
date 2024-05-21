class Jar:
    def __init__(self, capacity=12):
        if capacity < 0:
            raise ValueError("Positive Numbers Only")
        self._number_of_cookies = 0
        self._capacity = capacity

    def __str__(self):
        return  "🍪" * self._number_of_cookies

    def deposit(self, n):
        self._number_of_cookies += n
        if self._number_of_cookies > self.capacity:
            raise ValueError("Jar capacity exceeded")

    def withdraw(self, n):
        self._number_of_cookies -= n
        if self._number_of_cookies < 0:
            raise ValueError("Not enough cookies in the Jar")

    @property
    def capacity(self):
        return self._capacity

    @capacity.setter
    def capacity(self, value):
        self._capacity = value

    @property
    def size(self):
        return self._number_of_cookies

    @size.setter
    def size (self,value):
        self._size = value


def main():
    jar = Jar()
    print(str(jar.capacity))
    print(str(jar))
    jar.deposit(2)
    print(str(jar))
    jar.withdraw(1)
    print(str(jar))


main()
