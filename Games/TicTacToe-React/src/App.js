import React, { useState } from "react";
import Icon from "./components/Icon";

import { ToastContainer, toast } from "react-toastify";
import "react-toastify/dist/ReactToastify.css";

import "bootstrap/dist/css/bootstrap.min.css";
import { Card, CardBody, Button, Col, Row, Container } from "reactstrap";
import "./App.css";

const itemArray = new Array(9).fill("empty");

const App = () => {
	const [isCross, setIsCross] = useState(false);
	const [winMessage, setWinMessage] = useState("");

	const reloadGame = () => {
		setIsCross(false);
		setWinMessage("");
		itemArray.fill("empty", 0, 9);
	};

	const checkIsWinner = () => {
		if (
			itemArray[0] === itemArray[1] &&
			itemArray[1] === itemArray[2] &&
			itemArray[0] !== "empty"
		) {
			setWinMessage(`${itemArray[0]} won`);
		} else if (
			itemArray[3] === itemArray[4] &&
			itemArray[4] === itemArray[5] &&
			itemArray[3] !== "empty"
		) {
			setWinMessage(`${itemArray[3]} won`);
		} else if (
			itemArray[6] === itemArray[7] &&
			itemArray[7] === itemArray[8] &&
			itemArray[6] !== "empty"
		) {
			setWinMessage(`${itemArray[6]} won`);
		} else if (
			itemArray[0] === itemArray[3] &&
			itemArray[3] === itemArray[6] &&
			itemArray[0] !== "empty"
		) {
			setWinMessage(`${itemArray[0]} won`);
		} else if (
			itemArray[1] === itemArray[4] &&
			itemArray[4] === itemArray[7] &&
			itemArray[1] !== "empty"
		) {
			setWinMessage(`${itemArray[0]} won`);
		} else if (
			itemArray[2] === itemArray[5] &&
			itemArray[5] === itemArray[8] &&
			itemArray[2] !== "empty"
		) {
			setWinMessage(`${itemArray[2]} won`);
		} else if (
			itemArray[0] === itemArray[4] &&
			itemArray[4] === itemArray[8] &&
			itemArray[0] !== "empty"
		) {
			setWinMessage(`${itemArray[0]} won`);
		} else if (
			itemArray[2] === itemArray[4] &&
			itemArray[4] === itemArray[6] &&
			itemArray[2] !== "empty"
		) {
			setWinMessage(`${itemArray[2]} won`);
		}
	};

	const changeItem = (itemNumber) => {
		if (winMessage) {
			return toast(winMessage, { type: "success" });
		}
		if (itemArray[itemNumber] === "empty") {
			itemArray[itemNumber] = isCross ? "cross" : "circle";
			setIsCross(!isCross);
		} else {
			return toast("it is alredy filled", { type: "error" });
		}
		checkIsWinner();
	};

	return (
		<Container className='p-5'>
			<h1 className='text-center'>Tic Tac Toe</h1>
			<ToastContainer position='bottom-center' />
			<Row>
				<Col md={6} className='offset-md-3'>
					{winMessage ? (
						<div className='mt-2 mb-2'>
							<h1 className='text-center text-uppercase text-success'>
								{winMessage}
							</h1>
							<Button color='success' block onClick={reloadGame}>
								Reload
							</Button>
						</div>
					) : (
						<h1 className='text-center text-warning text-uppercase'>
							{isCross ? "cross" : "circle"} 's turn
						</h1>
					)}
					<div className='grid'>
						{itemArray.map((item, index) => (
							<Card className='card' onClick={() => changeItem(index)}>
								<CardBody className='box'>
									<Icon name={item} />
								</CardBody>
							</Card>
						))}
					</div>
				</Col>
			</Row>
		</Container>
	);
};

export default App;
