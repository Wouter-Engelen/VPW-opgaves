def valid?(string)
    xs = (0...string.size).select do |i|
        string[i] == '*'
    end

    deltas = xs.each_cons(2).map do |x, y|
        y - x
    end
    
    deltas.uniq.size == 1 and xs.first - deltas.first < 0 and xs.last + deltas.first >= string.size
end

class String
    def flip(i)
        r = self.dup
        r[i] = { '.' => '*', '*' => '.' }[self[i]]
        r
    end
end

def fix(string)
    (0...string.size).map do |i|
        string.flip i
    end.find do |str|
        valid? str
    end or string
end

ncases = gets.to_i

(1..ncases).each do |index|
    gets
    input = gets.strip
    solution = fix input
    puts "#{index} #{solution}"
end
