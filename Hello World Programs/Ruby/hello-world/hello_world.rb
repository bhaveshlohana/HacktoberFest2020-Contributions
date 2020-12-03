require 'ruby2d'
Image.new('images/hacktoberfest.png', x: 50, y: 30, width: 550, height: 400, z: 10)
Text.new('Click to see "Hello World!"', x: 200, y: 440, color: 'green')
on :mouse_down do |event|
    if event.button == :left && event.x >= 200 && event.x <= 440 && event.y <= 460 && event.y >= 440
        clear
        Image.new('images/hello_world.png', x: 10, y: 40, width: 400, height: 300, size: 100, z: 10)
    end
end
show
