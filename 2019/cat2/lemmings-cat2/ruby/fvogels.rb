ncases = gets.to_i

(1..ncases).each do |index|
    room_size = gets.to_i
    nlemmings = gets.to_i
    
    solution = (1..nlemmings).map do
        abort "Wrong input" unless /(\d+)([LR])/ =~ gets
        x, dir = $1.to_i, $2

        case dir
        when 'L'
            x
        when 'R'
            2 * room_size - x
        end
    end.max

    puts "#{index} #{solution}"
end