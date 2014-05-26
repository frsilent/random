local text

function love.load()
   love.graphics.setNewFont(12)
   text = "Nothing yet"
end

function love.update(dt)
    if love.keyboard.isDown( " " ) then
       text = "The SPACE key is held down!"
    -- else
    --     text = "Nothing yet"
    end
end

function love.draw()
   love.graphics.print( text, 330, 300 )
end

function love.keypressed( key )
    if key == "return" then
        text = "RETURN is being pressed!"
    end
    if key == 'h' then
        love.mouse.setVisible(not love.mouse.isVisible())
    end
end

function love.keyreleased( key )
   if key == "return" then
      text = "RETURN has been released!"
   end
end

function love.mousepressed(x, y, button)
   if button == 'l' then
      text = "Left mouse button has been pressed at X:"..x.." Y: "..y
   end
end

function love.mousereleased(x, y, button)
   if button == 'l' then
      text = "Left mouse button has been released"
   end
end