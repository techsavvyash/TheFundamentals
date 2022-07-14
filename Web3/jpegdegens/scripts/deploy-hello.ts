import "@nomiclabs/hardhat-ethers";
import { ethers } from "hardhat";

async function HelloWorldDeployUtility() {
  const HelloWorld = await ethers.getContractFactory("HelloWorld");
  const hello = await HelloWorld.deploy();
  await hello.deployed();

  return hello;
}

async function deploy() {
  const hello = await HelloWorldDeployUtility();

  return hello;
}

// @ts-ignore
async function sayHello(hello) {
  console.log("Say, Hello:", await hello.hello());
}

deploy().then(sayHello);
