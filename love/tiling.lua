function love.load()
    Tileset = love.graphics.newImage("countryside.png")
    Tileset_width, Tileset_height = Tileset:getWidth(), Tileset:getHeight() -- 64
    tile_width, tile_height = Tileset_width/2, Tileset_height/2             -- 32

    tiles = {
         love.graphics.newQuad(0, 0, tile_width, tile_height, Tileset_width, Tileset_height),      -- grass
         love.graphics.newQuad(32, 0, tile_width, tile_height, Tileset_width, Tileset_height),     -- box
         love.graphics.newQuad(0, 32, tile_width, tile_height, Tileset_width, Tileset_height),     -- flowers
         love.graphics.newQuad(32, 32, tile_width, tile_height, Tileset_width, Tileset_height)    -- box_top
    }

    TileTable = {
        { 4,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,4 },
        { 4,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,3,1,4 },
        { 4,1,3,1,1,1,1,1,1,1,1,1,1,1,1,3,1,1,1,1,1,1,1,1,4 },
        { 4,1,1,1,1,1,1,1,2,1,1,2,1,1,1,1,1,1,1,1,1,1,1,1,4 },
        { 4,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,4 },
        { 4,1,1,4,1,1,1,1,1,2,2,1,1,4,1,1,1,4,1,4,2,2,1,1,4 },
        { 4,1,1,4,1,1,1,1,4,3,3,4,1,2,1,1,1,2,1,4,1,1,1,1,4 },
        { 4,1,1,4,1,1,1,1,4,3,3,4,1,1,4,1,4,1,1,4,2,2,1,1,4 },
        { 4,1,1,4,1,1,1,1,4,3,3,4,1,1,2,1,2,1,1,4,1,1,1,1,4 },
        { 4,1,1,4,1,1,1,1,2,3,3,2,1,1,1,4,1,1,1,4,1,1,1,1,4 },
        { 4,1,1,2,2,2,2,1,1,2,2,1,1,1,1,2,1,3,1,2,2,2,1,1,4 },
        { 4,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,4 },
        { 4,1,1,1,1,1,1,1,1,2,1,1,1,1,2,2,4,1,1,1,1,1,1,1,4 },
        { 4,1,1,1,1,1,1,1,4,3,4,1,1,1,1,1,2,1,1,1,1,1,1,1,4 },
        { 4,1,1,3,1,1,1,1,2,3,2,1,1,1,1,2,1,1,1,1,1,1,1,1,4 },
        { 4,1,1,1,1,1,1,1,1,2,1,1,2,1,2,1,1,1,1,1,1,1,3,1,4 },
        { 4,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,4 },
        { 2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2 }
    }
end

function love.draw()
    for i=1, #TileTable do
        local row = TileTable[i]
        for j=1, #row do
            local tile = row[j]
            love.graphics.draw(Tileset, tiles[tile], (j-1)*tile_width, (i-1)*tile_height)
        end
    end
end

-- local quadInfo = {
--   {  0,  0 }, -- 1 = grass
--   { 32,  0 }, -- 2 = box
--   {  0, 32 }, -- 3 = flowers
--   { 32, 32 }  -- 4 = boxTop
-- }
-- Quads = {}
-- for i,info in ipairs(quadInfo) do
--   -- info[1] = x, info[2] = y
--   Quads[i] = love.graphics.newQuad(info[1], info[2], TileW, TileH, tilesetW, tilesetH)
-- end