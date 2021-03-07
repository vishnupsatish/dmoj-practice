books = list(input())

l_count = books.count('L')
m_count = books.count('M')
s_count = books.count('S')

l_section = books[:l_count]
m_section = books[l_count:l_count + m_count]
s_section = books[l_count + m_count:m_count + s_count + l_count]

print(s_section.count('M') + s_section.count('L') + max(l_section.count('M'), m_section.count('L')))
