class Conwaygame
    attr_accessor :world,:neighborhood
    def initialize(tamano)
        @world = Array.new(tamano+2){Array.new(tamano+2)} 
        @neighborhood  = Array.new(tamano+2){Array.new(tamano+2)}
    end

    def CrearMundo
        for x in 0..@world.size-1
            for y in 0..@world.size-1
                @world[x][y]=0
                @neighborhood[x][y]=0
            end
        end
    end

    def printstep
        @world.each_with_index do |e, row, col|
            puts "#{e}" 
        end
    end

    def printneighborhood
        @neighborhood.each_with_index do |e, row, col|
            puts "#{e}" 
        end
    end

    def CrearUniverso
        for x in 1..@world.size-2
            for y in 1..@world.size-2
                @world[x][y] = rand(0..1)
            end
        end     
    end 

    def next_step
        for x in 1..@world.size-2      
            for y in 1..@world.size-2
                vecinos=0
                if @world[x-1][y]==1 then 
                    vecinos += 1
                end
                if @world[x-1][y-1]==1 then 
                    vecinos += 1
                end
                if @world[x-1][y+1]==1 then 
                    vecinos += 1
                end
                if @world[x][y-1]==1 then 
                    vecinos += 1
                end
                if @world[x][y+1]==1 then 
                    vecinos += 1
                end
                if @world[x+1][y-1]==1 then 
                    vecinos += 1
                end
                if @world[x+1][y+1]==1 then 
                    vecinos += 1
                end
                if @world[x+1][y]==1 then 
                    vecinos += 1
                end 
               @neighborhood[x][y] = vecinos 
            end   
        end
    end 

    def findlife
        for x in 1..@world.size-2      
            for y in 1..@world.size-2
                if @world[x][y] == 1 then 
                    if(!(@neighborhood[x][y]==2 || @neighborhood[x][y]==3)) then
                        @world[x][y] = 0
                    end
                elsif @neighborhood[x][y]==3 then
                        @world[x][y] = 1 
                end
            end
        end  
    end 
end 

game = Conwaygame.new(4)
game.CrearMundo
game.CrearUniverso
game.printstep
game.next_step
puts "_____________________"
puts "   MATRIZ DE VECINO  "
game.printneighborhood
puts "---------------------"
puts " SIGUIENTE GENERACION "
game.findlife
game.printstep
