fizz_buzz =
    (1..100).map do |i|
        case
        when i % 15 == 0 then "FizzBuzz"
        when i % 3 == 0 then "Fizz"
        when i % 5 == 0 then "Buzz"
        else i
        end
    end
puts fizz_buzz