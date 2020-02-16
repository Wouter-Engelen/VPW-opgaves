ncases = int(input())

def column(col, xss):
    return [ xss[row][col] for row in range(len(xss)) ]

for index in range(1, ncases + 1):
    width, height = map(int, input().split(' '))
    rows = [ [ int(x) for x in input().split(' ') ] for _ in range(height) ]
    columns = [ column(k, rows) for k in range(width) ]
    totals = [ sum( column(col, rows) ) for col in range(width) ]
    columns_with_totals = [ column(k, rows + [totals]) for k in range(width) ]
    column_sizes = [ max(len(str(x)) for x in col) for col in columns_with_totals ]
    lines = [ " | ".join( str(datum).rjust(column_size) for datum, column_size in zip(row, column_sizes) ) for row in rows ]
    separator_line = "-+-".join( "-" * column_size for column_size in column_sizes )
    total_line = " | ".join( str(total).rjust(column_size) for total, column_size in zip(totals, column_sizes) )
    all_lines = lines + [ separator_line, total_line ]

    for line in all_lines:
        print(f'{index} {line}')
