class Book:
    def __init__(self, title, author, price):
        self.title = title
        self.author = author
        self.price = price

    def show_book(self):
        print("=" * 30)
        print(f"书名：{self.title}")
        print(f"作者：{self.author}")
        print(f"价格：{self.price}元")
        print("=" * 30)


book1 = Book(title="Python编程：从入门到实践", author="埃里克.马瑟斯", price=89.0)
book2 = Book(title="三体", author="刘慈欣", price=93.0)
book3 = Book(title="平凡的世界", author="路遥", price=68.0)

book1.show_book()
book2.show_book()
book3.show_book()
