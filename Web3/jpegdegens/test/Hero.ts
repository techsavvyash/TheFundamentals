import "@nomiclabs/hardhat-ethers";
import { ethers } from "hardhat";
import { expect } from "chai";

describe("Hero", function () {
  async function createHero() {
    const Hero = await ethers.getContractFactory("Hero");
    const hero = await Hero.deploy();
    await hero.deployed();

    return hero;
  }

  let hero;

  before(async function () {
    hero = await createHero();
  });

  it("should get a zero heroes array: ", async function () {
    expect(await hero.getHeroes()).to.deep.equal([]);
  });

  it("should fail at creating herp cause of payment", async function () {
    let e;
    try {
      await hero.createHero(0, {
        value: ethers.utils.parseEther("0.049999"),
      });
    } catch (err) {
      e = err;
    }

    expect(e.message.includes("Please send more money")).to.equal(true);
  });
});
