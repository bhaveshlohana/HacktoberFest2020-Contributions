package com.sumesh_pandit.tetris

import android.content.Context
import android.content.Intent
import androidx.appcompat.app.AppCompatActivity
import android.os.Bundle
import android.widget.ImageView
import kotlinx.android.synthetic.main.activity_main.*
import android.view.LayoutInflater
import android.widget.GridLayout
import androidx.lifecycle.Observer
import androidx.lifecycle.ViewModelProviders
import kotlin.random.Random

class MainActivity : AppCompatActivity() {

    val PREFS = "game_settings"
    val ROW = 36
    val COL = 20

    var gameOver = false
    var running = true
    var speed: Long = 300
    var points = 0
    var partId = Random.nextInt(0, 7)
    var part: Part = getRadomPart(partId, 0, COL / 2)

    private val ob1 = Observer<Int> {
        updateScore()
    }

    val vm: GameStateViewModel by lazy {
        ViewModelProviders.of(this)[GameStateViewModel::class.java]
    }

    var boardView = Array(ROW) {
        arrayOfNulls<ImageView>(COL)
    }

    var boardViewNextPart = Array(2) {
        arrayOfNulls<ImageView>(4)
    }

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_main)

        gridboard.rowCount = ROW
        gridboard.columnCount = COL
        gridboardNextPart.rowCount = 2
        gridboardNextPart.columnCount = 4

        val bundle: Bundle? = intent.extras

        if (bundle != null && GameState.saved) {
            vm.board = GameState.board
            vm.points = GameState.points
            part = GameState.part
        } else
            GameState.resetState()

        speed = getSharedPreferences(PREFS, Context.MODE_PRIVATE).getLong("speed", 200)

        initRender(boardView, gridboard, ROW, COL)
        initRender(boardViewNextPart, gridboardNextPart, 2, 4)

        btnLeft.setOnClickListener {
            if (checkColisionLeft())
                part.moveLeft()
        }

        btnRigth.setOnClickListener {
            if (checkColisionRight())
                part.moveRight()
        }

        btnDown.setOnClickListener {
            if (checkColisionX())
                part.moveDown()
        }

        btnRotate.setOnClickListener {

            if (checkColisionX()) {
                if (!checkColisionRight()) {
                    if (checkColisionLeft()) {
                        part.moveLeft()
                        part.rotate()
                    }
                }
                else if (!checkColisionLeft()) {
                    if (checkColisionRight()) {
                        part.moveRight()
                        part.rotate()
                    }
                } else
                    part.rotate()
            }

        }

        btnPause.setOnClickListener {
            if (running)
                running = false
            else {
                running = true
                gameRun()
            }
        }

        vm.notifyPoints.observe(this, ob1)
        updateScore()
        gameRun()
    }

    override fun onPause() {
        super.onPause()
        if (!gameOver)
            GameState.saveState(vm.points, vm.board, part)
        else
            GameState.resetState()
        running = false
    }

    override fun onRestart() {
        super.onRestart()
        running = true
        gameRun()
    }

    fun initRender(array: Array<Array<ImageView?>>, grid: GridLayout, row: Int, col: Int) {
        val inflater = LayoutInflater.from(this)
        for (i in 0 until row) {
            for (j in 0 until col) {
                array[i][j] =
                    inflater.inflate(R.layout.inflate_image_view, grid, false) as ImageView
                grid.addView(array[i][j])
            }
        }
    }

    fun getRadomPart(id: Int, row: Int, col: Int): Part {
        return when (id) {
            0 -> PartT(row, col)
            1 -> PartJ(row, col)
            2 -> PartZ(row, col)
            3 -> PartO(row, col)
            4 -> PartS(row, col)
            5 -> PartI(row, col)
            6 -> PartL(row, col)
            else ->  PartO(row, col)
        }
    }

    fun printPart(id: Int) {
        boardView[part.pointA.x][part.pointA.y]!!.setImageResource(getPixel(id))
        boardView[part.pointB.x][part.pointB.y]!!.setImageResource(getPixel(id))
        boardView[part.pointC.x][part.pointC.y]!!.setImageResource(getPixel(id))
        boardView[part.pointD.x][part.pointD.y]!!.setImageResource(getPixel(id))
    }

    fun printNextPart(id: Int) {
        clearScreen(boardViewNextPart, 2,4)
        val partNext = getRadomPart(id, 0, 1)
        boardViewNextPart[partNext.pointA.x][partNext.pointA.y]!!.setImageResource(getPixel(partNext.id))
        boardViewNextPart[partNext.pointB.x][partNext.pointB.y]!!.setImageResource(getPixel(partNext.id))
        boardViewNextPart[partNext.pointC.x][partNext.pointC.y]!!.setImageResource(getPixel(partNext.id))
        boardViewNextPart[partNext.pointD.x][partNext.pointD.y]!!.setImageResource(getPixel(partNext.id))
    }

    fun checkColisionX(): Boolean {
        return ((part.pointA.x + 1 < ROW && vm.board[part.pointA.x + 1][part.pointA.y] < 1) &&
                (part.pointB.x + 1 < ROW && vm.board[part.pointB.x + 1][part.pointB.y] < 1) &&
                (part.pointC.x + 1 < ROW && vm.board[part.pointC.x + 1][part.pointC.y] < 1) &&
                (part.pointD.x + 1 < ROW && vm.board[part.pointD.x + 1][part.pointD.y] < 1))
    }

    fun checkColisionRight(): Boolean {
        return ((part.pointA.y + 1 < COL && vm.board[part.pointA.x][part.pointA.y + 1] < 1) &&
                (part.pointB.y + 1 < COL && vm.board[part.pointB.x][part.pointB.y + 1] < 1) &&
                (part.pointC.y + 1 < COL && vm.board[part.pointC.x][part.pointC.y + 1] < 1) &&
                (part.pointD.y + 1 < COL && vm.board[part.pointD.x][part.pointD.y + 1] < 1))
    }

    fun checkColisionLeft(): Boolean {
        return ((part.pointA.y - 1 >= 0 && vm.board[part.pointA.x][part.pointA.y - 1] < 1) &&
                (part.pointB.y - 1 >= 0 && vm.board[part.pointB.x][part.pointB.y - 1] < 1) &&
                (part.pointC.y - 1 >= 0 && vm.board[part.pointC.x][part.pointC.y - 1] < 1) &&
                (part.pointD.y - 1 >= 0 && vm.board[part.pointD.x][part.pointD.y - 1] < 1))
    }

    fun destroy(row: Int) {
        vm.board[row] = Array(COL) { 0 }
        for (i in row downTo 1) {
            vm.board[i] = vm.board[i - 1]
        }
        vm.addScore(COL)
    }

    fun updateScore() {
        txtPoints.text = "${getResources().getString(R.string.points_label)} ${vm.points}"
    }

    fun showGameOver() {
        startActivity(Intent(this, GameOverActivity::class.java).putExtra("points", points))
        finish()
    }

    fun checkToDestroy() {
        for (i in 0 until ROW) {
            var cont = 0
            for (j in 0 until COL) {
                if (vm.board[i][j] == 0)
                    break
                else {
                    cont++
                    if (cont == COL)
                        destroy(i)
                }
            }
        }
    }

    fun getPixel(id: Int): Int {
        return when (id) {
            0 -> R.drawable.blackg1
            1 -> R.drawable.p1
            2 -> R.drawable.p2
            3 -> R.drawable.p3
            4 -> R.drawable.p4
            5 -> R.drawable.p5
            6 -> R.drawable.p6
            7 -> R.drawable.p7
            else -> R.drawable.p7
        }
    }

    fun clearScreen(array: Array<Array<ImageView?>>, row:Int, col: Int) {
        for (i in 0 until row)
            for (j in 0 until col)
                array[i][j]!!.setImageResource(getPixel(vm.board[i][j]))
    }

    fun movePart() {
        if (checkColisionX()) {
            if (part.pointA.x == 0) {
                partId = Random.nextInt(0, 7)

                printNextPart(partId)
            }
            part.moveDown()
            printPart(part.id)
        } else {
            if (part.pointA.x == 0) {
                running = false
                Thread.interrupted()
                gameOver = true
            }

            printPart(part.id)

            vm.board[part.pointA.x][part.pointA.y] = part.id
            vm.board[part.pointB.x][part.pointB.y] = part.id
            vm.board[part.pointC.x][part.pointC.y] = part.id
            vm.board[part.pointD.x][part.pointD.y] = part.id

            part = getRadomPart(partId, 0, COL / 2)
        }
    }

    fun gameRun() {

        clearScreen(boardViewNextPart, 2, 4)
        printNextPart(partId)
        Thread {
            while (running) {
                Thread.sleep(speed)
                runOnUiThread {
                    clearScreen(boardView, ROW, COL)
                    movePart()
                    checkToDestroy()
                }
            }
            if (gameOver)
                showGameOver()
        }.start()
    }
}
